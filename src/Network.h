#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <string>
#include <unordered_map>

#include "Node.h"

#include "City.h"
#include "Station.h"
#include "Reservoir.h"

class Network {
public:

    /* Constructor */
    Network();

    /* Destructor */
    ~Network();

    /* Getters */
    Node *getSuperSrc() const;
    Node *getSuperSink() const;
    const std::vector<City *> &getCitySet() const;
    const std::vector<Station *> &getStationSet() const;
    const std::vector<Reservoir *> &getReservoirSet() const;
    const std::unordered_map<std::string, Node *> &getNodeSet() const;

    /* Setters */
    void setSuperSrc(Node *superSrc);
    void setSuperSink(Node *superSink);
    void setCitySet(const std::vector<City *> &citySet);
    void setStationSet(const std::vector<Station *> &stationSet);
    void setReservoirSet(const std::vector<Reservoir *> &reservoirSet);
    void setNodeSet(std::unordered_map<std::string, Node *> &nodeSet);

    /* Functions */
    void createNetwork(const std::string& dataPath, bool small);
    Node *findNode(const std::string& nodeCode);
    void resetNetwork();

    /* Parsing */
    bool readStations(const std::string &fileLocation);
    bool readCities(const std::string &fileLocation);
    bool readReservoirs(const std::string &fileLocation);
    bool readPipes(const std::string &fileLocation);
    void readSuperElements();

    /* Max-Flow */
    bool findAugmentingPath(Node *s, Node *t);
    int findMinResidualAlongPath(Node *s, Node *t);
    void augmentFlowAlongPath(Node *s, Node *t, int f);
    int edmondsKarp(Node *s, Node *t);

private:

    Node* superSrc;
    Node* superSink;

    std::vector<City*> citySet;
    std::vector<Station*> stationSet;
    std::vector<Reservoir*> reservoirSet;

    std::unordered_map<std::string, Node *> nodeSet;

};

#endif /* NETWORK_H */
