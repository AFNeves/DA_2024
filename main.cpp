#include "Network.h"

#include "Node.h"

#include <iostream>

using namespace std;

int main()
{
    Network network;

    Node *s = network.findNode("S_SRC");
    Node *t = network.findNode("C_1");

    int maxFlow = network.edmondsKarp(s,t);

    cout << "\nMax Flow between " << s->getCode() << " and " << t->getCode() << ": " << maxFlow << endl;

    return 0;
}
