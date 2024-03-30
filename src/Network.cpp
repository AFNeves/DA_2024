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
    // Initialize a map to store the demand of each city
    unordered_map<string, int> cityDemands;

    // Retrieve demand for each city
    for (const auto& pair : network.getNodeSet()) {
        if (City* city = dynamic_cast<City*>(pair.second)) {
            cityDemands[city->getCode()] = city->getDemand();
        }
    }

    // Calculate the maximum flow from reservoirs to cities
    for (const auto& pair : network.getNodeSet()) {
        if (Reservoir* reservoir = dynamic_cast<Reservoir*>(pair.second)) {
            for (const auto& pair2 : network.getNodeSet()) {
                if (City* city = dynamic_cast<City*>(pair2.second)) {
                    int maxFlow = network.edmondsKarp(reservoir, city);
                    // Compare with city demand
                    if (maxFlow < cityDemands[city->getCode()]) {
                        int deficit = cityDemands[city->getCode()] - maxFlow;
                        cout << "City: " << city->getCode() << ", Deficit: " << deficit << endl;
                    }
                }
            }
        }
    }
}
