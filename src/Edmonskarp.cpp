//
// Created by lara2 on 17/03/2024.
//
#include <stdexcept>
#include <algorithm>
#include "Edmonskarp.h"
#include "Network.h"
#include "Pipe.h"
#include "Node.h"
#include <queue>
#include <limits>

//template <class T>
void Edmonskarp::testAndVisit(std::queue<Node *> &q, Node *src, Node *dest, double residual) {
    if (!dest->isVisited() && residual > 0) {
        dest->setVisited(true);
        dest->setPath(src);
        q.push(dest);
    }
}

//template <class T>
bool Edmonskarp::findAugmentingPath(Network &network, Node *s, Node *t) {
    for (auto& pair : network.getNodeSet()) {
        pair.second->setVisited(false);
    }

    s->setVisited(true);
    std::queue<Node *> q;
    q.push(s);

    while (!q.empty() && !t->isVisited()) {
        auto v = q.front();
        q.pop();

        for (auto& pipe : v->getAdj()) {
            testAndVisit(q, v, pipe->getDest(), pipe->getCapacity());
        }

        for (auto& pair : network.getNodeSet()) {
            Node* node = pair.second;
            for (auto& pipe : node->getAdj()) {
                if (pipe->getDest() == v) {
                    testAndVisit(q, v, node, pipe->getCapacity());
                }
            }
        }
    }

    return t->isVisited();
}

//template <class T>
double Edmonskarp::findMinResidualAlongPath(Node *s, Node *t) {
    double f = std::numeric_limits<double>::infinity();

    for (auto v = t; v != s; v = v->getPath()) {
        auto pipe = v->getPath()->getPipeTo(v);
        f = std::min(f, static_cast<double>(pipe->getCapacity()));
    }

    return f;
}


//template <class T>
void Edmonskarp::augmentFlowAlongPath(Node *s, Node *t, double f) {
    for (auto v = t; v != s; v = v->getPath()) {
        auto pipe = v->getPath()->getPipeTo(v);
        pipe->setCapacity(pipe->getCapacity() + f);
    }
}


//template <class T>
void Edmonskarp::edmondsKarp(Network &network, const std::string &sourceCode, const std::string &targetCode) {
    Node *s = network.findNode(sourceCode);
    Node *t = network.findNode(targetCode);

    if (s == nullptr || t == nullptr || s == t)
        throw std::logic_error("Invalid source and/or target node");

    for (auto& pair : network.getNodeSet()) {
        Node* node = pair.second;
        for (auto& pipe : node->getAdj()) {
            pipe->setCapacity(0);
        }
    }

    while (findAugmentingPath(network, s, t)) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}
