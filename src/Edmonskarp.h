//
// Created by lara2 on 17/03/2024.
//

#ifndef DA_2024_EDMONSKARP_H
#define DA_2024_EDMONSKARP_H

#include <stdexcept>
#include <algorithm>
#include "Network.h"
#include "Pipe.h"
#include "Node.h"
#include <queue>
#include <limits>


class Edmonskarp {
public:
    void testAndVisit(std::queue<Node *> &q, Node *src, Node *dest, int capacity, double residual);

    bool findAugmentingPath(Network &network, Node *s, Node *t);

    double findMinResidualAlongPath(Node *s, Node *t);

    void augmentFlowAlongPath(Node *s, Node *t, double f);

    void edmondsKarp(Network &network, const std::string &sourceCode, const std::string &targetCode);
};


#endif //DA_2024_EDMONSKARP_H
