#include "Pipe.h"

/* Constructor */

Pipe::Pipe(Node *src, Node *dest, int capacity) : src(src), dest(dest), capacity(capacity) {}

/* Getters */

Node *Pipe::getSrc() const { return src; }

Node *Pipe::getDest() const { return dest; }

int Pipe::getCapacity() const { return capacity; }

int Pipe::getFlow() const { return flow; }

/* Setters */

void Pipe::setSrc(Node *newNode) { src = newNode; }

void Pipe::setDest(Node *newNode) { dest = newNode; }

void Pipe::setCapacity(int newCapacity) { capacity = newCapacity; }

void Pipe::setFlow(int newFlow) { flow = newFlow; }