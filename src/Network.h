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

private:

    std::unordered_map<std::string, Node *> nodeSet;

};

#endif /* NETWORK_H */
