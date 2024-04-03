#include <valarray>
#include "Network.h"

#include "Node.h"
#include "Pipe.h"

using namespace std;

/* Constructor */

Network::Network()
{
    readCities("../data/Cities_Madeira.csv");
    readStations("../data/Stations_Madeira.csv");
    readReservoirs("../data/Reservoirs_Madeira.csv");
    readPipes("../data/Pipes_Madeira.csv");
}

/* Destructor */

Network::~Network() { for(auto& pair : nodeSet) { delete pair.second; } }

/* Getters */

const unordered_map<string, Node *> &Network::getNodeSet() const { return nodeSet; }

/* Setters */

void Network::setNodeSet(unordered_map<string, Node *> &newNodeSet) { nodeSet = newNodeSet; }

/* Functions */

int Network::getNumNodes() const { return (int) nodeSet.size(); }

Node *Network::findNode(const std::string& nodeCode)
{
    auto it = nodeSet.find(nodeCode);
    if (it != nodeSet.end()) return it->second;
    return nullptr;
}

bool Network::addPipe(const std::string& src, const std::string& dest, int capacity)
{
    Node *srcNode = findNode(src);
    Node *destNode = findNode(dest);

    if (srcNode != nullptr && destNode != nullptr)
    {
        (*srcNode).addPipe(destNode, capacity);
        return true;
    }

    return false;
}

bool Network::removePipe(const std::string& src, const std::string& dest)
{
    Node *srcNode = findNode(src);
    Node *destNode = findNode(dest);

    if (srcNode != nullptr && destNode != nullptr)
    {
        if ((*srcNode).removePipeTo(destNode)) return true;
    }

    return false;
}

void Network::resetNetwork()
{
    for (const auto& pair : nodeSet)
    {
        Node *node = pair.second;

        node->resetNode();

        for (auto pipe : node->getAdj()) { pipe->resetPipe(); }
    }
}

void Network::checkWaterSupply(Network& network) {
    // Iterate through each city
    for (const auto& pair : network.getNodeSet()) {
        if (City* city = dynamic_cast<City*>(pair.second)) {
            int totalCapacity = 0;

            // Calculate total water capacity being delivered to the city
            for (const auto& pair2 : network.getNodeSet()) {
                if (Reservoir* reservoir = dynamic_cast<Reservoir*>(pair2.second)) {
                    // Calculate max flow from reservoir to city
                    int maxFlow = network.edmondsKarp(reservoir, city);
                    totalCapacity += maxFlow;
                }
            }
            int deficit = totalCapacity - city->getDemand();
            cout << "City: " << city->getCode() << ", Deficit: " << deficit << endl;
            // Compare total capacity with city's demand

        }
    }
}

void Network::balanceFlow() {
    vector<int> differences;  // Diferenças entre capacidade e fluxo
    int totalDifference = 0;  // Total de diferenças
    int maxDifference = 0;     // Máxima diferença encontrada

    // Calcular as diferenças e encontrar a máxima diferença
    for (const auto& pair : nodeSet) {
        if (Pipe* pipe = dynamic_cast<Pipe*>(pair.second)) {
            int capacity = pipe->getCapacity();
            int flow = pipe->getFlow();
            int difference = capacity - flow;
            differences.push_back(difference);
            totalDifference += difference;
            maxDifference = max(maxDifference, difference);
        }
    }

    // Calcular a média das diferenças
    double averageDifference = totalDifference / differences.size();

    // Calcular a variância das diferenças
    double variance = 0;
    for (int diff : differences) {
        variance += pow(diff - averageDifference, 2);
    }
    variance /= differences.size();

    // Imprimir métricas antes do balanceamento
    cout << "Before balancing:" << endl;
    cout << "Average difference: " << averageDifference << endl;
    cout << "Variance: " << variance << endl;
    cout << "Max difference: " << maxDifference << endl;

    // Balancear o fluxo
    for (const auto& pair : nodeSet) {
        if (Pipe* pipe = dynamic_cast<Pipe*>(pair.second)) {
            int capacity = pipe->getCapacity();
            int flow = pipe->getFlow();
            int difference = capacity - flow;
            if (difference > maxDifference * 0.9) {
                // Redistribuir o fluxo para outras tubulações
                // (Implementação depende da estratégia de redistribuição escolhida)
                // Aqui, podemos simplesmente definir o fluxo para metade da capacidade
                pipe->setFlow(capacity / 2);
            }
        }
    }

    // Recalcular as métricas após o balanceamento
    // (Pode ser feito da mesma maneira que antes)

    // Imprimir métricas após o balanceamento
    cout << "\nAfter balancing:" << endl;
    // Imprimir métricas recalculadas
}

