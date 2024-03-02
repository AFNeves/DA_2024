#ifndef RESERVOIR_H
#define RESERVOIR_H

#include "Node.h"

class Reservoir : public Node {
public:

    /* Constructor */
    Reservoir(std::string name, std::string municipality, int id, std::string code, int maxDelivery);

    /* Getters */
    std::string getName() const;
    std::string getMunicipality() const;
    int getMaxDelivery() const;

    /* Setters */
    void setName(std::string newName);
    void setMunicipality(std::string newMunicipality);
    void setMaxDelivery(int newMaxDelivery);

private:

    std::string name;
    std::string municipality;
    int max_delivery;

};

#endif /* RESERVOIR_H */
