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
    int getNumNodes() const;
    Node *findNode(const std::string& nodeCode);
    bool addPipe(const std::string& src, const std::string& dest, int capacity);
    bool removePipe(const std::string& src, const std::string& dest);

private:

    std::unordered_map<std::string, Node *> nodeSet;

};

#endif /* NETWORK_H */
