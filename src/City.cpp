#include "City.h"

/* Constructor */

City::City(std::string name, int id, std::string code, float demand, int population) :
        Node(id, std::move(code)), name(std::move(name)), demand(demand), population(population) {}

/* Getters */

std::string City::getName() const { return name; }

float City::getDemand() const { return demand; }

int City::getPopulation() const { return population; }

/* Setters */

void City::setName(std::string newName) { City::name = std::move(newName); }

void City::setDemand(float newDemand) { City::demand = newDemand; }

void City::setPopulation(int newPopulation) { City::population = newPopulation; }