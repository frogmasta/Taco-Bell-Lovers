#include "graph.h"

using namespace std;

/**
 * Generates a list of strongly connected components
 *
 * @param node to start the algorithm on
 * @return vector of strongly connected components
 */
vector<vector<int>> Graph::StronglyConnectedComponents() const {
    vector<int> vertices = getVertices();
    if (vertices.empty()) return {};

    /* Step 1: DFS Traversal to populate scc_stack */
    stack<int> scc_stack;
    unordered_map<int, bool> visited;

    for (const int& v : vertices) {
        visited.insert({v, false});
    }

    Graph* reversed = transpose();
    
    for (const int& v : vertices) {
        if (!visited.at(v)) {
            visited.at(v) = true;
            reversed->scc_dfs(v, visited, scc_stack);
        }
    }

    /* Step 2: Perform another DFS traversal in order of scc_stack */
    for (const int& v : vertices) {
        visited.at(v) = false;
    }

    vector<vector<int>> strongly_connected_components;
    while(!scc_stack.empty()) {
        int currVertex = scc_stack.top();
        scc_stack.pop();
        if (!visited.at(currVertex)) {
            visited.at(currVertex) = true;
            strongly_connected_components.push_back(scc_dfs(currVertex, visited, scc_stack));
        }
    }

    delete reversed;
    return strongly_connected_components;
}

/**
 * Provides a transposed version of the graph (i.e. reversing the edge direction)
 *
 * @return transposed graph
 */
Graph* Graph::transpose() const {
    Graph* newGraph = new Graph();

    for (const int& v : getVertices()) {
        for (const Edge& e : getEdges(v)) {
            newGraph->addEdge(e.dest, e.source, e.weight, true);
        }
    }

    return newGraph;
}

/** 
 * Recursive DFS traversal for SCC. Called on the graph being explored.
 *
 * @return vector of nodes visited starting at this node in DFS
 */
vector<int> Graph::scc_dfs(int currVertex, unordered_map<int, bool>& visited, stack<int>& scc_stack) const {
    vector<Edge> edges = getEdges(currVertex);
    vector<int> traversal;
    traversal.push_back(currVertex);

    for (const Edge& e : edges) {
        if (!visited.at(e.dest)) {
            visited.at(e.dest) = true;
            vector<int> rec_traversal = scc_dfs(e.dest, visited, scc_stack);
            traversal.insert(traversal.end(), rec_traversal.begin(), rec_traversal.end());
        }
    }

    scc_stack.push(currVertex);
    return traversal;
}