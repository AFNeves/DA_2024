#include "Network.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include "City.h"
#include "Station.h"
#include "Reservoir.h"

using namespace std;

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

        auto city = new City(Name, stoi(ID), Code, stof(Demand), Population);
        city->setCapacity(stoi(Demand));

        nodeSet[Code] = city;

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

        auto reservoir = new Reservoir(Name, Municipality, stoi(ID), Code, stoi(MaxDelivery));
        reservoir->setCapacity(stoi(MaxDelivery));

        nodeSet[Code] = reservoir;

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

bool Network::readSuperElements()
{
    auto src = new Node(0, "S_SRC");
    auto sink = new Node(0, "S_SINK");

    for (auto pair : nodeSet)
    {
        if (pair.second->getCode().substr(0,1) == "R")
            src->addPipe(pair.second, INT16_MAX);

        if (pair.second->getCode().substr(0,1) == "C")
            pair.second->addPipe(sink, INT16_MAX);
    }

    nodeSet["S_SRC"] = src;
    nodeSet["S_SINK"] = sink;

    return true;
}
