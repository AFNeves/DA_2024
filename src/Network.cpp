#include "Network.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

/* Constructor */

Network::Network() {}

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

bool Network::addNode(int id, const std::string& code) {

    if (findNode(code) != nullptr)
        return false;


    Node* newNode = new Node(id, code);
    nodeSet[code] = newNode;
    return true;
}

bool Network::removeNode(int id, const std::string& code) {

    Node* nodeToRemove = findNode(code);


    if (nodeToRemove == nullptr || nodeToRemove->getID() != id)
        return false;


    for (auto& pair : nodeSet) {
        Node* node = pair.second;
        node->removePipeTo(nodeToRemove);
    }


    nodeSet.erase(code);
    delete nodeToRemove;
    return true;
}

/* Parsing */
/*
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

        if(Township[0] == '"'){
            getline(file, temp, '"');
            Township += "," + temp;
            temp = "";
            for(int i=1; i<Township.size()-1; i++){
                temp+=Township[i];
            }
        }
        getline(file, Line);

        bool insert = true;
        for (auto station : stations) {
            if (station->getName() == Name) {
                insert = false;
                break;
            }
        }

        if (insert == true) {
            stations.push_back(new Station(Name, District, Municipality, Township, Line));
        }

        n++;
    }

    file.close();
    return n;
}*/

