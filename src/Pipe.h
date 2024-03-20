#ifndef PIPE_H
#define PIPE_H

class Node;

class Pipe {
public:
    friend class Node;

    /* Constructor */
    Pipe(Node *src, Node *dest, int capacity);

    /* Getters */
    Node *getSrc() const;
    Node *getDest() const;
    int getCapacity() const;
    int getFlow() const;

    /* Setters */
    void setSrc(Node *newNode);
    void setDest(Node *newNode);
    void setCapacity(int newCapacity);
    void setFlow(int newFlow);

private:

    Node *src;
    Node *dest;
    int capacity;
    int flow;

};

#endif //PIPE_H