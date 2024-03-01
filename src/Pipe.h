#ifndef PIPE_H
#define PIPE_H

#include "Node.h"

class Pipe {
public:

    /* Constructor */
    Pipe(Node *a, Node *b, int capacity, bool biDirection);

    /* Getters */
    Node *getA() const;
    Node *getB() const;
    int getCapacity() const;
    bool isBiDirectional() const;

    /* Setters */
    void setA(Node *newNode);
    void setB(Node *newNode);
    void setCapacity(int newCapacity);
    void setBiDirection(bool newDirection);

private:

    Node *A;
    Node *B;
    int capacity;
    bool biDirection;

};

#endif //PIPE_H
