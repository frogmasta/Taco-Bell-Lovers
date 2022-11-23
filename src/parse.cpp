#include "parse.h"

using std::stoi;
using std::string;
using std::to_string;
using std::vector;

const int ELEMENTS_PER_LINE = 3;

Parser::Parser() = default;

/**
 * Helper function to determine if a string is an integer or not
 *
 * @param num input string
 * @return true if the input is a string, false otherwise
 */
bool Parser::isInteger(const string& num) {
    /* A blank number is not an integer */
    if (num.length() < 1) return false;

    /* Remove leading negative sign */
    size_t startidx = 0;
    if (num[0] == '-') {
        startidx = 1;
        if (num.length() < 2) return false;
    }

    /* Check to make sure everything is a digit */
    for (size_t i = startidx; i < num.length(); ++i) {
        if (!isdigit(num[i])) return false;
    }

    return true;
}

/**
 * Generates list of edges from a given .csv file [source, dest, weight, time=optional]
 *
 * @param fname .csv file name
 * @return edge-list in vector form
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
        for (const char& c : line) {
            if (c == ',') edge.push_back("");
            else edge.back() += c;
        }

        /* Throw out invalid values */
        if (edge.size() < 3 || !isInteger(edge[0]) || !isInteger(edge[1]) || !isInteger(edge[2])) continue;

        /* Check that the weight is a valid integer between -10 and 10 */
        int w = stoi(edge[2]);
        if (w < -10 || w > 10) continue;

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
 * @return generated graph
 */
Graph* Parser::generateGraph(const string &fname, bool edge_aggregation=false) {
    /* Extract info from file */
    vector<Edge> edgeList = readFile(fname);
    Graph* g = new Graph();

	/* Add edges to the graph */
    for (const Edge& e : edgeList) {
    	g->addEdge(e.source, e.dest, e.weight, edge_aggregation);
    }

    /* Return finished product */
    return g;
}