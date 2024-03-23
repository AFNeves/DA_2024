// NetworkManager.cpp
#include "NetworkManager.h"
#include "Edmonskarp.h"
#include <fstream>
#include <map>
#include <algorithm>

void NetworkManager::determineMaxFlowToCities(Network& network,
                                              const std::vector<Reservoir>& reservoirs,
                                              const std::vector<City>& cities,
                                              const std::vector<Station>& stations) {
    std::map<std::string, int> maxFlowToCities;

    // Para cada reservatório na rede
    for (const auto& reservoir : reservoirs) {
        Edmonskarp edmonds;
        // Atualizar o mapa de fluxo máximo para cidades
        for (const auto& city : cities) {
            edmonds.edmondsKarp(network, reservoir.getCode(), city.getCode());

            int cityFlow = 0;
            for (const auto& pipe : city.getPipesIn()) {
                cityFlow += pipe->getFlow(); // Somar os fluxos das tubulações de entrada da cidade
            }
            maxFlowToCities[city.getCode()] += cityFlow;
        }

        // Resetar os fluxos na rede para a próxima iteração
        network.resetFlows();
    }

    // Exibir os resultados
    std::cout << "Fluxo máximo para cada cidade:" << std::endl;
    for (const auto& pair : maxFlowToCities) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Escrever os resultados em um arquivo
    std::ofstream outputFile("max_flow_results.txt");
    if (outputFile.is_open()) {
        for (const auto& pair : maxFlowToCities) {
            outputFile << pair.first << ": " << pair.second << std::endl;
        }
        outputFile.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo de saída para escrita" << std::endl;
    }
}