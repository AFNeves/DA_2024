#include "Network.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

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

        auto station = new Station(stoi(ID), Code);

        nodeSet[Code] = station;
        stationSet.push_back(station);

        n++;
    }

    std::sort(stationSet.begin(), stationSet.end(), [](Station* a, Station* b) {
        return a->getID() < b->getID();
    });

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
        city->setCapacity(stoi(Demand)); city->setCapacityValue(stoi(Demand));

        nodeSet[Code] = city;
        citySet.push_back(city);

        n++;
    }

    std::sort(citySet.begin(), citySet.end(), [](City* a, City* b) {
        return a->getID() < b->getID();
    });

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
        reservoir->setCapacity(stoi(MaxDelivery)); reservoir->setCapacityValue(stoi(MaxDelivery));

        nodeSet[Code] = reservoir;
        reservoirSet.push_back(reservoir);

        n++;
    }

    std::sort(reservoirSet.begin(), reservoirSet.end(), [](Reservoir* a, Reservoir* b) {
        return a->getID() < b->getID();
    });

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
        getline(ss, Direction, '\r');

        Node *src = findNode(SRC);
        Node *dest = findNode(DEST);

        if (src == nullptr || dest == nullptr) return false;

        src->addPipe(dest, stoi(Capacity));

        if (Direction == "0") { dest->addPipe(src, 0); n++; }

        n++;
    }

    file.close();
    return true;
}

void Network::readSuperElements()
{
    for (const auto& pair : nodeSet)
    {
        if (pair.second->getCode().substr(0,1) == "R")
            superSrc->addPipe(pair.second, INT16_MAX);

        if (pair.second->getCode().substr(0,1) == "C")
            pair.second->addPipe(superSink, INT16_MAX);
    }

    nodeSet["S_SRC"] = superSrc;
    nodeSet["S_SINK"] = superSink;
}
