#pragma once

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

#include "edge.h"

/* 
 * Class implementation of a weighted, signed, directed Graph
 */
class Graph {
    public:
        Graph();

        bool vertexExists(int v) const;
        bool edgeExists(int src, int dest) const;

        std::vector<int> getVertices() const;
        std::vector<Edge> getEdges(int v) const;

        bool addVertex(int v);
        bool addEdge(int src, int dest, int weight);

        void printGraph() const;
    private:
        std::unordered_map<int, std::vector<Edge>> adjList;
};