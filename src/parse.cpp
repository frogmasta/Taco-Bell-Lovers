#include "parse.h"

using std::stoi;
using std::string;
using std::to_string;
using std::vector;

Parser::Parser() {
    /* do nothing */
}

/**
 * Generates list of edges from a given .csv file [source, dest, weight, time=optional]
 *
 * @param .csv file
 *
 * @return edge list in vector form
 */
vector<Parser::EdgeInfo> Parser::readFile(string fname) {
    /* Initialization */
    vector<EdgeInfo> out;
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
        EdgeInfo newInfo(stoi(edge[0]), stoi(edge[1]), stoi(edge[2]));
        out.push_back(newInfo);
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
Graph* Parser::generateGraph(string fname) {
    vector<EdgeInfo> edgeList = readFile(fname);

    for (auto e : edgeList) {
        std::cout << "Edge: " << e.source << " " << e.dest << " " << e.weight << std::endl;
    }

    return NULL;
}