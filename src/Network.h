#ifndef NETWORK_H
#define NETWORK_H

#include <queue>
#include <string>
#include <unordered_map>
#include <iostream>
#include "City.h"
#include "Reservoir.h"

#include "Node.h"

using namespace std;

class Network {
public:

    /* Constructor */
    Network();

    /* Destructor */
    ~Network();

    /* Getters */
    const std::unordered_map<std::string, Node *> &getNodeSet() const;

    /* Setters */
    void setNodeSet(std::unordered_map<std::string, Node *> &nodeSet);

    /* Functions */
    int getNumNodes() const;
    Node *findNode(const std::string& nodeCode);
    bool addPipe(const std::string& src, const std::string& dest, int capacity);
    bool removePipe(const std::string& src, const std::string& dest);
    void resetNetwork();

    /* Parsing */
    bool readStations(const std::string &fileLocation);
    bool readCities(const std::string &fileLocation);
    bool readReservoirs(const std::string &fileLocation);
    bool readPipes(const std::string &fileLocation);

    /* Max-Flow */
    bool findAugmentingPath(Node *s, Node *t);
    int findMinResidualAlongPath(Node *s, Node *t);
    void augmentFlowAlongPath(Node *s, Node *t, int f);
    int edmondsKarp(Node *s, Node *t);

    /*Deficit*/
    static void checkWaterSupply(Network& network);

private:

    std::unordered_map<std::string, Node *> nodeSet;

};

#endif /* NETWORK_H */
