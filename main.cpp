/*#include <iostream>

#include "src/Station.h"
#include "src/Pipe.h"

using namespace std;

int main()
{
    Station station1(3,"S-09");
    Station station2(6,"S-52");

    Pipe pipe(&station1, &station2, 50, false);

    cout << "\nStation | ID:" << pipe.getA()->getID() << " Code:" << pipe.getA()->getCode() << "\n";
    cout << "\nStation | ID:" << pipe.getB()->getID() << " Code:" << pipe.getB()->getCode() << "\n";
    cout << "\nPipe | Capacity:" << pipe.getCapacity() << " IsDirection:" << pipe.isBiDirectional() << "\n\n";

    return 0;
}*/
/*
#include <iostream>
#include <vector>

#include "src/NetworkManager.h"
#include "src/Reservoir.h"
#include "src/City.h"
#include "src/Station.h"

int main() {
    // Criar instâncias de reservatórios
    std::vector<Reservoir> reservoirs;
    reservoirs.push_back(Reservoir("Ribeira do Seixal", "Porto Moniz", 1, "R_1", 525));
    reservoirs.push_back(Reservoir("Serra de Água", "Ponta do Sol", 2, "R_2", 300));

    // Criar instâncias de cidades
    std::vector<City> cities;
    cities.push_back(City("Porto Moniz", 1, "C_1", 18.00, 2517)); // Uma dúvida no ultimo tipo de dados
    cities.push_back(City("São Vicente", 2, "C_2", 34.00, 4865));
    cities.push_back(City("Santana", 3, "C_3", 46.00, 553));

    // Criar instâncias de estações e tubulações
    std::vector<Station> stations;
    stations.push_back(Station(1, "PS_1", 100, "R_1", "PS_1"));   // Exemplo de uma estação conectando City1 e City2
    stations.push_back(Station(2, "PS_2", 400, "R_1", "PS_2"));   // Exemplo de uma estação conectando City2 e City3

    // Chamar a função para determinar o fluxo máximo para as cidades
    NetworkManager::determineMaxFlowToCities(reservoirs, cities, stations);

    return 0;
}*/

#include <iostream>
#include "src/Network.h"

int main() {
    Network network;

    // Adiciona alguns nós à rede
    network.addNode(1, "A");
    network.addNode(2, "B");
    network.addNode(3, "C");

    // Adiciona algumas tubulações entre os nós
    network.addPipe("A", "B", 10);
    network.addPipe("B", "C", 20);

    // Remove um nó da rede
    network.removeNode(2, "B");

    // Verifica se o nó foi removido corretamente
    if (network.findNode("B") == nullptr) {
        std::cout << "Node B foi removido com sucesso.\n";
    } else {
        std::cout << "Erro: O nó B ainda está presente na rede.\n";
    }

    return 0;
}

