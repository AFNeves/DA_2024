#include "Node.h"
#include "Pipe.h"

/* Constructor */

Node::Node(int id, std::string code) : id(id), code(std::move(code)),
                                       visited(false), processing(false), indegree(0), num(0), low(0) {}

/* Destructor */

Node::~Node() { for(Pipe* pipe : adj) { delete pipe; } }

/* Getters */

int Node::getID() const { return id; }

std::string Node::getCode() const { return code; }

bool Node::isVisited() const { return visited; }

bool Node::isProcessing() const { return processing; }

int Node::getIndegree() const { return indegree; }

int Node::getNum() const { return num; }

int Node::getLow() const { return low;}

const std::vector<Pipe *> &Node::getAdj() const { return adj; }

/* Setters */

void Node::setID(int newID) { id = newID; }

void Node::setCode(std::string newCode) { code = std::move(newCode); }

void Node::setVisited(bool boolean) { visited = boolean; }

void Node::setProcessing(bool boolean) { processing = boolean; }

void Node::setIndegree(int newIndegree) { indegree = newIndegree; }

void Node::setNum(int newNum) { num = newNum; }

void Node::setLow(int newLow) { low = newLow; }

void Node::setAdj(std::vector<Pipe *> &newAdj) { adj = newAdj; }

/* Operators */

bool Node::operator==(const Node &rhs) const { return id == rhs.id && code == rhs.code; }

bool Node::operator!=(const Node &rhs) const { return id != rhs.id || code != rhs.code; }

/* Functions */

void Node::addPipe(Node *dest, int capacity)
{
    adj.push_back(new Pipe(this, dest, capacity));
}

bool Node::removePipeTo(Node *dest)
{
    for (auto it = adj.begin(); it != adj.end(); it++)
        if ((*it)->dest == dest)
        {
            adj.erase(it);
            return true;
        }
    return false;
}