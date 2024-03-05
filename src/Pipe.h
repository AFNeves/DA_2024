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

    /* Setters */
    void setSrc(Node *newNode);
    void setDest(Node *newNode);
    void setCapacity(int newCapacity);

private:

    Node *src;
    Node *dest;
    int capacity;

};

#endif //PIPE_H
