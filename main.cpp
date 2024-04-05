#include "Network.h"

#include "Node.h"

#include <iostream>

using namespace std;

int main()
{
    Network network;

    Node *s = network.findNode("S_SRC");
    Node *t = network.findNode("S_SINK");

    int maxFlow = network.edmondsKarp(s, t);

    for (const auto& pair : network.getNodeSet())
        if (pair.second->getCode().substr(0,1) == "C")
            cout << "\n" << pair.second->getCode() << ": " << pair.second->getCapacityValue() - pair.second->getCapacity() << endl;

    cout << "\nTotal Max Flow: " << maxFlow << endl;

    return 0;
}
