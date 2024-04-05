#include "Network.h"
#include "Reservoir.h"

#include "Node.h"

#include <iostream>

using namespace std;

int main()
{
    Network network;

    Node *s = network.findNode("S_SRC");
    vector <Node *> cities;
    vector <int> maxFlows;
    int expected_total_flow = 0;

    for(int i = 1 ; i < 11; ++i){

        Node *t = network.findNode("C_" + to_string(i));
        cities.push_back(t);

        int maxFlow = network.edmondsKarp(s, t);
        maxFlows.push_back(maxFlow);
        expected_total_flow += maxFlow;

        cout << "\nMax Flow between " << s->getCode() << " and " << t->getCode() << ": " << maxFlow << endl;
    }

    cout << "\nExpected_total_flow: " << expected_total_flow << endl;

    int funchalDemand = cities[5]->getCapacity();
    int funchalActualFlow = maxFlows[5];
    cout << "\nC_6-Funchal" << "\nDemand: " << cities[5]->getCapacity() << "\nActual Flow: " << funchalActualFlow << "\nDeficit: " << funchalDemand - funchalActualFlow << endl;


    network.resetNetwork();

    Node *r = network.findNode("R_4");
    delete r;

    cout << network.edmondsKarp(s, cities[5]) << endl;


    return 0;
}
