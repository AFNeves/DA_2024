#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class Pipe;

class Node {
public:
    friend class Pipe;

    /* Constructor */
    Node(int id, std::string code);

    /* Destructor */
    virtual ~Node();

    /* Getters */
    int getID() const;
    std::string getCode() const;
    bool isVisited() const;
    bool isProcessing() const;
    int getIndegree() const;
    int getNum() const;
    int getLow() const;
    const std::vector<Pipe *> &getAdj() const;

    /* Setters */
    void setID(int newID);
    void setCode(std::string newCode);
    void setVisited(bool visited);
    void setProcessing(bool processing);
    void setIndegree(int indegree);
    void setNum(int num);
    void setLow(int low);
    void setAdj(std::vector<Pipe *> &adj);

    /* Operators */
    bool operator==(const Node &rhs) const;
    bool operator!=(const Node &rhs) const;

    /* Functions */
    void addPipe(Node *dest, int capacity);
    bool removePipeTo(Node *dest);

    Node* getPath() const;
    void setPath(Node* newPath);

    Pipe *getPipeTo(Node *pNode) const;
    void setPipeTo(Pipe* newPipe);

private:

    int id;
    std::string code;
    bool visited;
    bool processing;
    int indegree;
    int num;
    int low;
    std::vector<Pipe *> adj;
    Node* path;
    Pipe* pipeTo;

};

#endif /* NODE_H */