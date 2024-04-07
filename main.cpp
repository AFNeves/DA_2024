#include "Network.h"
#include "Reservoir.h"

#include "Node.h"

#include <iostream>

using namespace std;

void citiesFlows(vector<int> &maxFlows, vector<Node *> &cities, Network &network , Node *s, int &expected_total_flow){
    for(int i = 1 ; i < 11; ++i){

        Node *t = network.findNode("C_" + to_string(i));
        cities.push_back(t);

        int maxFlow = network.edmondsKarp(s, t);
        maxFlows.push_back(maxFlow);
        expected_total_flow += maxFlow;

        cout << "\nMax Flow between " << s->getCode() << " and " << t->getCode() << ": " << maxFlow << endl;
    }
}

int main()
{
    Network network;

    Node *s = network.findNode("S_SRC");
    vector <Node *> cities;
    vector <int> maxFlows;
    int expected_total_flow = 0;

    citiesFlows(maxFlows, cities, network, s, expected_total_flow);

    cout << "\nExpected_total_flow: " << expected_total_flow << endl;

    int funchalDemand = cities[5]->getCapacity();
    int funchalActualFlow = maxFlows[5];
    cout << "\nC_6-Funchal" << "\nDemand: " << cities[5]->getCapacity() << "\nActual Flow: " << funchalActualFlow << "\nDeficit: " << funchalDemand - funchalActualFlow << endl;


    network.resetNetwork();

    Node *ribeiro_frio = network.findNode("R_4");
    delete ribeiro_frio;

    cout << "Machico: " << "Old Flow: " << maxFlows[3] << " New Flow: " << network.edmondsKarp(s, cities[3]) << endl;
    cout << "Santa Cruz: " << "Old Flow: " << maxFlows[4] << " New Flow: " << network.edmondsKarp(s, cities[4]) << endl;
    cout << "Funchal: " << "Old Flow: " << maxFlows[5] << " New Flow: " << network.edmondsKarp(s, cities[5]) << endl;

    network.resetNetwork();
    cout << endl;

    Network network1;

    cout << endl;

    Node *ps1 = network1.findNode("PS_1");
    Node *s1 = network1.findNode("S_SRC");
    delete ps1;

    cout << "Santa Cruz: " << "Old Flow: " << maxFlows[4] << " New Flow: " << network1.edmondsKarp(s1, cities[4]) << endl;
    cout << "Funchal: " << "Old Flow: " << maxFlows[5] << " New Flow: " << network1.edmondsKarp(s1, cities[5]) << endl;
    cout << "Porto Moniz: " << "Old Flow: " << maxFlows[0] << " New Flow: " << network1.edmondsKarp(s1, cities[0]) << endl;
    cout << "Calheta: " << "Old Flow: " << maxFlows[9] << " New Flow: " << network1.edmondsKarp(s1, cities[9]) << endl;


    cout << "\nCase 1:\n";

    Network network2;

    Node *s2 = network2.findNode("S_SRC");
    Node *ps9 = network2.findNode("PS_9");
    Node *ps10 = network2.findNode("PS_10");
    delete ps9;
    delete ps10;
    maxFlows.clear();
    cities.clear();
    expected_total_flow = 0;

    citiesFlows(maxFlows, cities, network2, s2, expected_total_flow);

    cout << "\nCase 2:\n";

    Network network3;

    Node *s3 = network3.findNode("S_SRC");
    Node *ps4 = network3.findNode("PS_4");
    Node *ps5 = network3.findNode("PS_5");
    delete ps4;
    delete ps5;
    maxFlows.clear();
    cities.clear();
    expected_total_flow = 0;

    citiesFlows(maxFlows, cities, network, s3, expected_total_flow);


    cout << "\nCase 3:\n";

    Network network4;

    Node *s4 = network4.findNode("S_SRC");
    Node *ps4_ = network4.findNode("PS_4");
    Node *ps5_ = network4.findNode("PS_5");
    Node *ps9_ = network4.findNode("PS_9");
    Node *ps10_ = network4.findNode("PS_10");

    delete ps9_;
    delete ps10_;
    delete ps4_;
    delete ps5_;


    maxFlows.clear();
    cities.clear();
    expected_total_flow = 0;

    citiesFlows(maxFlows, cities, network, s4, expected_total_flow);
    return 0;
}
