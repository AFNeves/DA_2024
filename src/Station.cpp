#include "Station.h"

// Constructor implementation
Station::Station(int id, std::string code, int capacity, std::string code_A, std::string code_B)
        : Node(id, code), capacity(capacity), code_A(code_A), code_B(code_B) {}

// Getter implementations
std::string Station::getCode_A() const {
    return code_A;
}

std::string Station::getCode_B() const {
    return code_B;
}
