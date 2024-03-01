#include "Pipe.h"

/* Constructor */

Pipe::Pipe(Node *a, Node *b, int capacity, bool biDirection) : A(a), B(b), capacity(capacity), biDirection(biDirection) {}

/* Getters */

Node *Pipe::getA() const { return A; }

Node *Pipe::getB() const { return B; }

int Pipe::getCapacity() const { return capacity; }

bool Pipe::isBiDirectional() const { return biDirection; }

/* Setters */

void Pipe::setA(Node *newNode) { A = newNode; }

void Pipe::setB(Node *newNode) { B = newNode; }

void Pipe::setCapacity(int newCapacity) { Pipe::capacity = newCapacity; }

void Pipe::setBiDirection(bool newDirection) { Pipe::biDirection = newDirection; }
