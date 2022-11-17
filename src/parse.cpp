#include "parse.h"

using std::stoi;
using std::string;
using std::to_string;
using std::vector;

Parser::Parser() = default;

/**
 * Generates list of edges from a given .csv file [source, dest, weight, time=optional]
 *
 * @param .csv file
 *
 * @return edge list in vector form
 */
vector<Edge> Parser::readFile(const string& fname) {
    /* Initialization */
    vector<Edge> out;
    std::ifstream infile(fname);

    /* Parse .csv file line by line */
    string line;
    while(std::getline(infile, line)) {
        /* Extract info into edge vector [source, dest, weight, time=optional] */
        vector<string> edge = { "" };
        for (char c : line) {
            if (c == ',') edge.push_back("");
            else edge.back() += c;
        }

        if (edge.size() < 3) continue;  // If it's missing an entry we skip it

        /* Add information to out vector */
        Edge newEdge(stoi(edge[0]), stoi(edge[1]), stoi(edge[2]));
        out.push_back(newEdge);
    }

    return out;
}

/**
 * Generates a graph from a given .csv file
 *
 * @param file where graph is stored
 * 
 * @return generated graph
 */
Graph* Parser::generateGraph(const string &fname, bool edge_aggregation) {
    /* Extract info from file */
    vector<Edge> edgeList = readFile(fname);
    Graph* g = new Graph();


    /* Add edges to the graph */
    if (edge_aggregation) {

      for (const Edge& edge : edgeList) {
        if (g->edgeExists(edge.source, edge.dest)) {
          int prevWeight = g->getEdge(edge.source, edge.dest).weight;
          g->setEdge(edge.source, edge.dest, (prevWeight + edge.weight) / 2);
        } else {
          g->addEdge(edge.source, edge.dest, edge.weight);
        }
      }

    } else {
      for (const Edge& e : edgeList) {
        g->addEdge(e.source, e.dest, e.weight);
      }
    }

    /* Return finished product */
    return g;
}