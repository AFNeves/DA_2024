#ifndef PIPE_H
#define PIPE_H

class Node;

class Pipe {
public:
	friend class Node;
    friend class Network;

    /* Constructor */
    Pipe(Node *src, Node *dest, int capacity);

    /* Getters */
    Node *getSrc() const;
    Node *getDest() const;
    int getFlow() const;
    int getCapacity() const;
    int getResidual() const;

    /* Setters */
    void setSrc(Node *newNode);
    void setDest(Node *newNode);
    void setFlow(int newFlow);
    void setCapacity(int newCapacity);
    void setResidual(int newResidual);

    /* Functions */
    void resetPipe();

private:

    Node *src;
    Node *dest;
    int flow;
    int capacity;
    int residual;

};

#endif //PIPE_H
