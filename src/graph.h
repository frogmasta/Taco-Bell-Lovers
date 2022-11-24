#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
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
        Edge getEdge(int src, int dest) const;

        bool addVertex(int v);
        bool addEdge(int src, int dest, double weight, bool edge_aggregation);

        std::vector<int> bfs(int v) const;

        void printGraph() const;
    private:
        void bfs_helper(int v, std::vector<int>& traversal, std::unordered_map<int, bool>& labeling) const;

        std::unordered_map<int, std::vector<Edge>> adjList;
};