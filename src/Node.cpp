#include "Node.h"

/* Constructor */

Node::Node(int id, std::string code) : id(id), code(std::move(code)) {}

/* Getters */

int Node::getID() const { return id; }

std::string Node::getCode() const { return code; }

/* Setters */

void Node::setID(int newID) { Node::id = newID; }

void Node::setCode(std::string newCode) { Node::code = std::move(newCode); }

/* Operators */

bool Node::operator==(const Node &rhs) const { return id == rhs.id && code == rhs.code; }

bool Node::operator!=(const Node &rhs) const { return id != rhs.id || code != rhs.code; }
