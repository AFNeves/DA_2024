#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:

    /* Constructor */
    Node(int id, std::string code);

    /* Getters */
    int getId() const;
    std::string getCode() const;

    /* Setters */
    void setId(int newID);
    void setCode(std::string newCode);

    /* Operators */
    bool operator==(const Node &rhs) const;
    bool operator!=(const Node &rhs) const;

private:

    int id;
    std::string code;

};

#endif /* NODE_H */
