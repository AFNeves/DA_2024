#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:

    /* Constructor */
    Node(int id, std::string code);

    /* Getters */
    int getID() const;
    std::string getCode() const;

    /* Setters */
    void setID(int newID);
    void setCode(std::string newCode);

    /* Operators */
    bool operator==(const Node &rhs) const;
    bool operator!=(const Node &rhs) const;

private:

    int id;
    std::string code;

};

#endif /* NODE_H */