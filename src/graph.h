#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#include "edge.h"

/* 
 * Class implementation of a weighted, signed, directed Graph.
 */
class Graph {
    public:
        Graph() = default;

        bool vertexExists(int v) const;
        bool edgeExists(int src, int dest) const;

        std::vector<int> getVertices() const;
        std::vector<Edge> getEdges(int v) const;
        std::vector<int> getNeighbors(int v) const;
        Edge getEdge(int src, int dest) const;
        std::unordered_map<int, std::vector<Edge>> getAdjList() const {return adjList;};

        bool isEdgeAggregated () const {return edge_aggregated;};

        bool addVertex(int v);
        bool addEdge(int src, int dest, double weight, bool edge_aggregation);

        std::vector<int> bfs(int v) const;

        std::vector<std::vector<int>> StronglyConnectedComponents(int cutoffWeight=0) const;

        std::unordered_map<int, double> PageRank() const;

        void printGraph() const;
    private:
        void bfs_helper(int v, std::vector<int>& traversal, std::unordered_map<int, bool>& labeling) const;

        Graph* transpose() const;
        Graph* removeEdges(int cutoffWeight) const;
        std::vector<int> scc_dfs(int currVertex, std::unordered_map<int, bool>& visited, std::stack<int>& scc_stack) const;

        double PageRankHelper(int v, const std::unordered_map<int, double>& prev) const;

        std::unordered_map<int, std::vector<Edge>> adjList;
        bool edge_aggregated {false};
};
