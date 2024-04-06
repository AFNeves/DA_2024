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

Network::~Network() { deleteNetwork(); delete superSrc; delete superSink; }

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

void Network::deleteNetwork()
{
    auto it1 = nodeSet.find("S_SRC");
    auto it2 = nodeSet.find("S_SINK");
    if (it1 != nodeSet.end() && it2 != nodeSet.end()) {
        nodeSet.erase(it1); nodeSet.erase(it2);
    }

    for (auto pipe : superSrc->adj)
        delete pipe;
    superSrc->adj.clear();

    for (const auto &pair: nodeSet)
        delete pair.second;
    nodeSet.clear();

    citySet.clear();
    stationSet.clear();
    reservoirSet.clear();
}

void Network::createNetwork(const std::string &dataPath, bool small)
{
    deleteNetwork();
    readCities(small ? "../data/small/Cities_Madeira.csv" : dataPath + "Cities.csv");
    readStations(small ? "../data/small/Stations_Madeira.csv" : dataPath + "Stations.csv");
    readReservoirs(small ? "../data/small/Reservoirs_Madeira.csv" : dataPath + "Reservoir.csv");
    readPipes(small ? "../data/small/Pipes_Madeira.csv" : dataPath + "Pipes.csv");
    readSuperElements();
}

Node *Network::findNode(const std::string& nodeCode)
{
    auto it = nodeSet.find(nodeCode);
    if (it != nodeSet.end()) return it->second;
    return nullptr;
}

void Network::resetNetwork()
{
    for (const auto& pair : nodeSet)
    {
        pair.second->resetNode();
        for (auto pipe : pair.second->getAdj()) { pipe->resetPipe(); }
    }
}
