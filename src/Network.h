#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <unordered_map>

#include "Node.h"

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
    Node *findNode(const std::string& nodeCode);
    bool addPipe(const std::string& src, const std::string& dest, int capacity);
    bool removePipe(const std::string& src, const std::string& dest);
    void resetNetwork();

    /* Parsing */
    bool readStations(const std::string &fileLocation);
    bool readCities(const std::string &fileLocation);
    bool readReservoirs(const std::string &fileLocation);
    bool readPipes(const std::string &fileLocation);
    bool readSuperElements();

    /* Max-Flow */
    bool findAugmentingPath(Node *s, Node *t);
    int findMinResidualAlongPath(Node *s, Node *t);
    void augmentFlowAlongPath(Node *s, Node *t, int f);
    int edmondsKarp(Node *s, Node *t);

private:

    std::unordered_map<std::string, Node *> nodeSet;

};

#endif /* NETWORK_H */
