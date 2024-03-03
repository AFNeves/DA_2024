// In NetworkManager.cpp

#include "NetworkManager.h"
#include "Graph.h"
#include <fstream>
#include <map>
#include <algorithm>

void determineMaxFlowToCities(const std::vector<Reservoir>& reservoirs,
                              const std::vector<City>& cities,
                              const std::vector<Station>& stations) {
    // Criar um grafo e preenchê-lo com nós e arestas
    Graph<std::string> graph;

    // Adicionar reservatórios como nós de origem
    for (const auto& reservoir : reservoirs) {
        graph.addVertex(reservoir.getCode());
    }

    // Adicionar cidades como nós intermediários
    for (const auto& city : cities) {
        graph.addVertex(city.getCode());
    }

    // Adicionar arestas representando tubulações conectando nós
    for (const auto& station : stations) {
        // Supondo que cada estação conecta dois nós (A e B) via tubulações
        graph.addBidirectionalEdge(station.getCode_A(), station.getCode_B(), station.getCapacity());
    }

    // Calcular o fluxo máximo para cada cidade usando o algoritmo de Edmonds-Karp
    std::map<std::string, int> maxFlowToCities; // Mapa para armazenar o fluxo máximo para cada cidade

    for (const auto& reservoir : reservoirs) {
        // Para cada reservatório, encontrar o fluxo máximo para todas as cidades
        std::map<std::string, int> maxFlowFromReservoir = graph.findMaxFlow(reservoir.getCode(), "destination");

        // Mesclar o fluxo máximo deste reservatório com o fluxo máximo geral para as cidades
        for (const auto& pair : maxFlowFromReservoir) {
            maxFlowToCities[pair.first] = std::max(maxFlowToCities[pair.first], pair.second);
        }
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
