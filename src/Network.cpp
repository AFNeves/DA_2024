#include "Network.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include "City.h"
#include "Station.h"
#include "Reservoir.h"

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

/* Parsing */

bool Network::readStations(const std::string &fileLocation) {

    std::fstream file;
    file.open(fileLocation, ios::in);
    if (!file.is_open()) {
        std::cout << "ERROR - The function \"readStations\" could not read the data" << std::endl;
        return false;
    }

    std::string line;
    getline(file, line); // Skip fist line

    int n = 0;
    std::string ID, Code;

    while (getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream ss(line);

        getline(ss, ID, ',');
        getline(ss, Code, ',');

        if (Code.empty()) continue;

        nodeSet[Code] = new Station(stoi(ID), Code);

        n++;
    }

    std::cout << "SUCCESS : readStations read " << n << " stations!" << std::endl;

    file.close();
    return true;
}

bool Network::readCities(const std::string &fileLocation) {

    std::fstream file;
    file.open(fileLocation, ios::in);
    if (!file.is_open()) {
        std::cout << "ERROR - The function \"readCities\" could not read the data" << std::endl;
        return false;
    }

    std::string line;
    getline(file, line); // Skip fist line

    int n = 0;
    std::string ID, Code, Name, Demand, Population;

    while (getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream ss(line);

        getline(ss, Name, ',');
        getline(ss, ID, ',');
        getline(ss, Code, ',');
        getline(ss, Demand, ',');
        getline(ss, Population, '\"');
        getline(ss, Population, '\"');

        if (Code.empty()) continue;

        nodeSet[Code] = new City(Name, stoi(ID), Code, stof(Demand), Population);

        n++;
    }

    std::cout << "SUCCESS : readCities read " << n << " cities!" << std::endl;

    file.close();
    return true;
}

bool Network::readReservoirs(const std::string &fileLocation) {

    std::fstream file;
    file.open(fileLocation, ios::in);
    if (!file.is_open()) {
        std::cout << "ERROR - The function \"readReservoirs\" could not read the data" << std::endl;
        return false;
    }

    std::string line;
    getline(file, line); // Skip fist line

    int n = 0;
    std::string ID, Code, Name, Municipality, MaxDelivery;

    while (getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream ss(line);

        getline(ss, Name, ',');
        getline(ss, Municipality, ',');
        getline(ss, ID, ',');
        getline(ss, Code, ',');
        getline(ss, MaxDelivery, ',');

        if (Code.empty()) continue;

        nodeSet[Code] = new Reservoir(Name, Municipality, stoi(ID), Code, stoi(MaxDelivery));

        n++;
    }

    std::cout << "SUCCESS : readReservoirs read " << n << " reservoirs!" << std::endl;

    file.close();
    return true;
}

bool Network::readPipes(const std::string &fileLocation) {

    std::fstream file;
    file.open(fileLocation, ios::in);
    if (!file.is_open()) {
        std::cout << "ERROR - The function \"readPipes\" could not read the data" << std::endl;
        return false;
    }

    std::string line;
    getline(file, line); // Skip fist line

    int n = 0;
    std::string SRC, DEST, Capacity, Direction;

    while (getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream ss(line);

        getline(ss, SRC, ',');
        getline(ss, DEST, ',');
        getline(ss, Capacity, ',');
        getline(ss, Direction, ',');

        Node *src = findNode(SRC);
        Node *dest = findNode(DEST);

        if (src == nullptr || dest == nullptr) return false;

        src->addPipe(dest, stoi(Capacity));

        if (Direction == "1") { dest->addPipe(src, stoi(Capacity)); }

        n++;
    }

    std::cout << "SUCCESS : readPipes read " << n << " pipes!" << std::endl;

    file.close();
    return true;
}
