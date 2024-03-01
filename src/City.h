#ifndef CITY_H
#define CITY_H

#include "Node.h"

class City : public Node {
public:

    /* Constructor */
    City(std::string name, int id, std::string code, float demand, int population);

    /* Getters */
    std::string getName() const;
    float getDemand() const;
    int getPopulation() const;

    /* Setters */
    void setName(std::string newName);
    void setDemand(float newDemand);
    void setPopulation(int newPopulation);

private:

    std::string name;
    float demand;
    int population;

};

#endif /* CITY_H */
