#include "Network.h"

#include "Node.h"

#include <iostream>

using namespace std;

int main()
{
    Network network;

    Node *s = network.findNode("R_4");
    Node *t = network.findNode("C_3");

    int maxFlow = network.edmondsKarp(s,t);

    cout << "\nMax Flow between " << s->getCode() << " and " << t->getCode() << ": " << maxFlow << endl;

    Network::checkWaterSupply(network);


    network.balanceFlow();

    return 0;
}
