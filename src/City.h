#ifndef CITY_H
#define CITY_H

#include "Node.h"

class City : public Node {
public:

    /* Constructor */
    City(std::string name, int id, std::string code, float demand, std::string population);

    /* Getters */
    std::string getName() const;
    float getDemand() const;
    std::string getPopulation() const;

    /* Setters */
    void setName(std::string newName);
    void setDemand(float newDemand);
    void setPopulation(std::string newPopulation);

    // Método para adicionar uma tubulação de entrada à cidade
    void addPipeIn(Pipe* pipe) { pipesIn.push_back(pipe); }

    // Método para obter as tubulações de entrada da cidade
    const std::vector<Pipe*>& getPipesIn() const { return pipesIn; }

private:

    std::string name;
    float demand;
    std::string population;
    std::vector<Pipe*> pipesIn;

};

#endif /* CITY_H */