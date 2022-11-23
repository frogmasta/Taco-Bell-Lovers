#include "graph.h"

using std::cout;
using std::endl;
using std::pair;
using std::vector;

Graph::Graph() = default;

/** 
 * Checks whether a given vertex exists in the graph
 *
 * @param v vertex to check
 * @return true if in the graph, false otherwise
 */
bool Graph::vertexExists(int v) const {
    return (adjList.find(v) != adjList.end());
}

/**
 * Checks whether a given edge exists in the graph
 * 
 * @param src source vertex
 * @param dest destination vertex
 * @return true if it's in the graph, false otherwise
 */
bool Graph::edgeExists(int src, int dest) const {
    if (!vertexExists(src) || !vertexExists(dest)) return false; // Not possible if it exists

    /* Checks every outgoing edge from src */
    Edge comparison(src, dest, 0);
    for (const Edge& e : adjList.at(src)) {
        if (e == comparison) return true;
    }

    /* Didn't find a match */
    return false;
}

/**
 * Generates a list of every vertex in the graph
 *
 * @return vector of graph vertices
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
 * @param v source vertex
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
 * Gets an edge from the graph
 *
 * @param src source vertex
 * @param dest desination vertex
 */
Edge Graph::getEdge(int src, int dest) const {
    if (!vertexExists(src) || !vertexExists(dest)) return Edge(); // Return a blank if neither vertex exists

    /* Loop through possible edge matches */
    vector<Edge> edges = adjList.at(src);
    for (const Edge& edge : edges) {
        if (edge.dest == dest) return edge;
    }

    /* No match was found */
    return Edge();
}

/**
 * Adds a new vertex to the graph
 *
 * @param v new vertex
 * @return true if add was successful, false otherwise
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
 * @param src source vertex
 * @param dest destination vertex
 * @param weight weight of the edge to add
 * @return true if successful, false otherwise
 */
bool Graph::addEdge(int src, int dest, double weight, bool edge_aggregation) {
    /* Add vertices if not in graph */
    if (!vertexExists(src)) addVertex(src);
    if (!vertexExists(dest)) addVertex(dest);

    /* Search source vertex for existing edge */
    vector<Edge>& edges = adjList.at(src);
    for (Edge& e : edges) {
        if (e.dest != dest) continue;

        /* Change edge if edge_aggregation is on */
        if (edge_aggregation) {
            e.weight = (weight + e.weight) / 2;
            return true;
        } else {
            return false;
        }
    }

    /* Did not find in the adjacency list */
    adjList[src].push_back(Edge(src, dest, weight));
    return true;
}

/*
 * Prints a simple representation of the current graph
 */
void Graph::printGraph() const {
    cout << "Generated graph: " << endl;

    vector<int> vertices = getVertices();
    for (int v : vertices) {
        cout << v << ": ";
        vector<Edge> edges = getEdges(v);
        for (Edge e : edges) {
            cout << "(" << e.dest << ", " << e.weight << "), ";
        }
        cout << endl;
    }
}