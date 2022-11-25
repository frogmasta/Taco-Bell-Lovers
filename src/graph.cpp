#include "graph.h"

using std::cout;
using std::endl;
using std::pair;
using std::vector;

Graph::Graph() = default;

/** 
 * Checks whether a given vertex exists in the graph.
 *
 * @param v vertex to check
 * @return true if in the graph, false otherwise
 */
bool Graph::vertexExists(int v) const {
    return (adjList.find(v) != adjList.end());
}

/**
 * Checks whether a given edge exists in the graph.
 * 
 * @param src source vertex
 * @param dest destination vertex
 * @return true if it's in the graph, false otherwise
 */
bool Graph::edgeExists(int src, int dest) const {
    if (!vertexExists(src) || !vertexExists(dest)) return false; // Not possible if it exists

    Edge comparison(src, dest, 0);
    for (const Edge& e : adjList.at(src)) {
        if (e == comparison) return true;
    }

    return false;
}

/**
 * Generates a list of every vertex in the graph.
 *
 * @return vector of graph vertices
 */
vector<int> Graph::getVertices() const {
    vector<int> out;

    for (pair<int, vector<Edge>> entry : adjList) {
        out.push_back(entry.first);
    }

    return out;
}

/**
 * Generates a list of edges for a given vertex.
 *
 * @param v source vertex
 * @return vector with it's outgoing edges (will return empty if vertex doesn't exist)
 */
vector<Edge> Graph::getEdges(int v) const {
    if (vertexExists(v)) {
        return adjList.at(v);
    }

    return {};
}

/**
 * Gets an edge from the graph.
 *
 * @param src source vertex
 * @param dest desination vertex
 */
Edge Graph::getEdge(int src, int dest) const {
    if (!vertexExists(src) || !vertexExists(dest)) return {};

    vector<Edge> edges = adjList.at(src);
    for (const Edge& edge : edges) {
        if (edge.dest == dest) return edge;
    }

    return {};
}

/**
 * Adds a new vertex to the graph
 *
 * @param v new vertex
 * @return true if add was successful, false otherwise
 */
bool Graph::addVertex(int v) {
    if (vertexExists(v)) return false;

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

  if (!vertexExists(src)) addVertex(src);
  if (!vertexExists(dest)) addVertex(dest);

  vector<Edge>& edges = adjList.at(src);
  for (Edge& e : edges) {
      if (e.dest != dest) continue;

      // Crucial for duplicate edges with different weights (when edge_aggregation is on)
      if (edge_aggregation) {
          e.weight = (weight + e.aggregation_count * e.weight) / (e.aggregation_count + 1);
          e.aggregation_count += 1;
          return true;
      }
      else return false;
  }

  adjList[src].push_back(Edge(src, dest, weight));
  return true;
}

/*
 * Prints a simple representation of the current graph!
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