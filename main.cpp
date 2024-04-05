#include "Network.h"

#include "Node.h"

#include <iostream>

using namespace std;

int main()
{
    Network network;
    network.readSuperElements();

    Node *s = network.findNode("S_SRC");
    Node *t = network.findNode("S_SINK");

    int maxFlow = network.edmondsKarp(s,t);

    cout << "\nMax Flow between " << s->getCode() << " and " << t->getCode() << ": " << maxFlow << endl;

    return 0;
}
