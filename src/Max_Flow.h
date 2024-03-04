//
// Created by lara2 on 04/03/2024.
//

#ifndef DA_2024_MAX_FLOW_H
#define DA_2024_MAX_FLOW_H

#include "Graph.h"
#include <queue>
#include <limits>
#include <map>

class Max_Flow {
public:
    template <class T>
    void testAndVisit(std::queue< Vertex<T>*> &q, Edge<T> *e, Vertex<T> *w, double residual);

    template <class T>
    bool findAugmentingPath(Graph<T> *g, Vertex<T> *s, Vertex<T> *t);

    template <class T>
    double findMinResidualAlongPath(Vertex<T> *s, Vertex<T> *t);

    template <class T>
    void augmentFlowAlongPath(Vertex<T> *s, Vertex<T> *t, double f);

    template <class T>
    void edmondsKarp(Graph<T> *g, int source, int target);
};


#endif //DA_2024_MAX_FLOW_H
