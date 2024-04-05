#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class Pipe;

class Node {
public:
    friend class Pipe;
    friend class Network;

    /* Constructor */
    Node(int id, std::string code);

    /* Destructor */
    virtual ~Node();

    /* Getters */
    int getID() const;
    std::string getCode() const;
    bool isVisited() const;
    int getCapacity() const;
    int getCapacityValue() const;
    Node *getParent() const;
    const std::vector<Pipe *> &getAdj() const;

    /* Setters */
    void setID(int newID);
    void setCode(std::string newCode);
    void setVisited(bool visited);
    void setCapacity(int capacity);
    void setCapacityValue(int capacityValue);
    void setParent(Node *parent);
    void setAdj(std::vector<Pipe *> &adj);

    /* Operators */
    bool operator==(const Node &rhs) const;
    bool operator!=(const Node &rhs) const;

    /* Functions */
    void addPipe(Node *dest, int capacity, bool direction);
    bool removePipeTo(Node *dest);
    Pipe* getPipeTo(Node *dest);
    void resetNode();

private:

    int id;
    std::string code;
    bool visited;
    int capacity;
    int capacityValue;
    Node* parent;
    std::vector<Pipe *> adj;

};

#endif /* NODE_H */
