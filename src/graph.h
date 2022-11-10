#pragma once

#include <unordered_map>
#include <vector>

/* 
 * Class implementation of a weighted, signed, directed Graph
 */
class Graph {
    public:
        Graph();

    private:
        /* Interface for an edge */
        struct Edge {
            int dest;
            int weight;
        };

        std::unordered_map<int, std::vector<Edge>> adjList;
};