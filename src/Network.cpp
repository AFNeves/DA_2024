#include "Network.h"

#include "Pipe.h"

using namespace std;

/* Constructor */

Network::Network()
{
    superSrc = new Node(0, "S_SRC");
    superSink = new Node(0, "S_SINK");
}

/* Destructor */

Network::~Network() { for(auto& pair : nodeSet) { delete pair.second; } }

/* Getters */

Node *Network::getSuperSrc() const { return superSrc; }

Node *Network::getSuperSink() const { return superSink; }

const vector<City *> &Network::getCitySet() const { return citySet; }

const vector<Station *> &Network::getStationSet() const { return stationSet; }

const vector<Reservoir *> &Network::getReservoirSet() const { return reservoirSet; }

const unordered_map<string, Node *> &Network::getNodeSet() const { return nodeSet; }

/* Setters */

void Network::setSuperSrc(Node *newSuperSrc) { superSrc = newSuperSrc; }

void Network::setSuperSink(Node *newSuperSink) { superSink = newSuperSink; }

void Network::setCitySet(const vector<City *> &newCitySet) { citySet = newCitySet; }

void Network::setStationSet(const vector<Station *> &newStationSet) { stationSet = newStationSet; }

void Network::setReservoirSet(const vector<Reservoir *> &newReservoirSet) { reservoirSet = newReservoirSet; }

void Network::setNodeSet(unordered_map<string, Node *> &newNodeSet) { nodeSet = newNodeSet; }

/* Functions */

void Network::createNetwork(const std::string &dataPath, bool small)
{
    if (small)
    {
        readCities("../data/small/Cities_Madeira.csv");
        readStations("../data/small/Stations_Madeira.csv");
        readReservoirs("../data/small/Reservoirs_Madeira.csv");
        readPipes("../data/small/Pipes_Madeira.csv");
    }
    else
    {
        readCities(dataPath + "Cities.csv");
        readStations(dataPath + "Stations.csv");
        readReservoirs(dataPath + "Reservoirs.csv");
        readPipes(dataPath + "Pipes.csv");
    }
    readSuperElements();
}

Node *Network::findNode(const std::string& nodeCode)
{
    auto it = nodeSet.find(nodeCode);
    if (it != nodeSet.end()) return it->second;
    return nullptr;
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
        pair.second->resetNode();
        for (auto pipe : pair.second->getAdj()) { pipe->resetPipe(); }
    }
}
