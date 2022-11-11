/* Will be updated to include graph functionality */

#include "graph.h"

using std::cout;
using std::endl;
using std::pair;
using std::vector;

Graph::Graph() { }

/** 
 * Checks whether a given vertex exists in the graph
 *
 * @param vertex to check
 * @return true if in the graph, false otherwise
 */
bool Graph::vertexExists(int v) const {
    return (adjList.find(v) != adjList.end());
}

bool Graph::edgeExists(int src, int dest) const {
    if (!vertexExists(src) || !vertexExists(dest)) return false; // Not possible if it exists

    /* Checks every outgoing edge from src */
    Edge comparison(src, dest, 0);
    for (Edge e : adjList.at(src)) {
        if (e == comparison) return true;
    }

    /* Didn't find a match */
    return false;
}

/**
 * Generates a list of every vertex in the graph
 *
 * @return vector of vertices
 */
vector<int> Graph::getVertices() const {
    vector<int> out;

    /* Iterate through map and add all the keys */
    for (pair<int, vector<Edge>> entry : adjList) {
        out.push_back(entry.first);
    }

    return out;
}

/**
 * Generates a list of edges for a given vertex
 *
 * @param vertex
 * @return vector with it's outgoing edges (will return empty if vertex doesn't exist)
 */
vector<Edge> Graph::getEdges(int v) const {
    /* Return edge vector at v */
    if (vertexExists(v)) {
        return adjList.at(v);
    }

    /* Default return value if v doesn't exist */
    return vector<Edge>();
}

/**
 * Adds a new vertex to the graph
 *
 * @return true if successful, false otherwise
 */
bool Graph::addVertex(int v) {
    if (vertexExists(v)) return false;  // Already in the graph

    /* Insert into graph */
    adjList.insert({v, vector<Edge>()});
    return true;
}

/**
 * Adds a new edge to the graph
 *
 * @return true if successful, false otherwise
 */
bool Graph::addEdge(int src, int dest, int weight) {
    /* Add vertices if not in graph */
    if (!vertexExists(src)) addVertex(src);
    if (!vertexExists(dest)) addVertex(dest);

    /* Add if it's not in the graph */
    if (!edgeExists(src, dest)) {
        adjList[src].push_back(Edge(src, dest, weight));
        return true;
    }

    /* Unsuccessful */
    return false;
}

/*
 * Prints a simple representation of the current graph
 */
void Graph::printGraph() {
    cout << "Graph- " << endl;

    vector<int> vertices = getVertices();
    for (int v : vertices) {
        cout << v << ": ";
        vector<Edge> edges = getEdges(v);
        for (Edge e : edges) {
            cout << e.dest << " ";
        }
        cout << endl;
    }
}