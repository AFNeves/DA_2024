// Station.h
#ifndef STATION_H
#define STATION_H

#include "Node.h"

class Station : public Node {
public:
    // Constructor with additional arguments for A and B codes
    Station(int id, std::string code, int capacity, std::string code_A, std::string code_B);

    // Default constructor
    Station() = default;

    // Getter para a capacidade
    int getCapacity() const { return capacity; }

    // Getters for A and B codes
    std::string getCode_A() const;
    std::string getCode_B() const;

private:
    int capacity; // Capacidade da estação
    std::string code_A; // Code of end point A
    std::string code_B; // Code of end point B
};

#endif /* STATION_H */
