#include "parse.h"

using std::stoi;
using std::string;
using std::to_string;
using std::vector;

Parser::Parser() = default;

/**
 * Helper function to trim whitespace from the beginning/end of a string.
 *
 * @param str string to remove whitespace
 */
void Parser::trim(string& str) {
    size_t newstart = str.find_first_not_of(" \n\r\t\f\v");
    str = str.substr(newstart);

    size_t newend = str.find_last_not_of(" \n\r\t\f\v");
    str = str.substr(0, newend+1);
}

/**
 * Helper function to determine if a string is an integer or not
 *
 * @param num input string
 * @return true if the input is a string, false otherwise
 */
bool Parser::isInteger(const string& num) {
    // An empty string is not an integer
    if (num.length() < 1) return false;

    // Handles possible negative sign
    size_t startidx = 0;
    if (num[0] == '-') {
        startidx = 1;
        if (num.length() < 2) return false;
    }

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
    vector<Edge> out;
    std::ifstream infile(fname);

    // Possible error has occured 
    if (!infile.is_open()) return {};

    string line;
    while(std::getline(infile, line)) {
        vector<string> edge = { "" };
        for (const char& c : line) {
            if (c == ',') {
                trim(edge.back());
                edge.push_back("");
            }
            else edge.back() += c;
        }
        trim(edge.back()); // necessary to trim the final edge piece

        // Invalid values
        if (edge.size() < 3 || !isInteger(edge[0]) || !isInteger(edge[1]) || !isInteger(edge[2])) continue;

        // Weight must be in [-10, 10] 
        int w = stoi(edge[2]);
        if (w < -10 || w > 10) continue;

        Edge newEdge(stoi(edge[0]), stoi(edge[1]), stoi(edge[2]));
        out.push_back(newEdge);
    }

    infile.close();
    return out;
}

/**
 * Generates a graph from a given .csv file
 *
 * @param file where graph is stored
 * @return generated graph
 */
Graph* Parser::generateGraph(const std::string &fname, bool edge_aggregation) {
    vector<Edge> edgeList = readFile(fname);

    // Possible error 
    if (edgeList.empty()) return nullptr;

    Graph* g = new Graph();
    for (const Edge& e : edgeList) {
        g->addEdge(e.source, e.dest, e.weight, edge_aggregation);
    }

    return g;
}