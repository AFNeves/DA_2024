#include "Network.h"

using namespace std;

/* Constructor */

Network::Network() {}

/* Destructor */

Network::~Network() { for(auto& pair : nodeSet) { delete pair.second; } }

/* Getters */

const unordered_map<string, Node *> &Network::getNodeSet() const { return nodeSet; }

/* Setters */

void Network::setNodeSet(unordered_map<string, Node *> &newNodeSet) { nodeSet = newNodeSet; }
