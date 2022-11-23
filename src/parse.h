#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "graph.h"
#include "edge.h"

/* Class to render the csv files into workable graphs */
class Parser {
    public:
        Parser();

        static Graph* generateGraph(const std::string &fname, bool edge_aggregation);
    private:
        static std::vector<Edge> readFile(const std::string& fname);
        static bool isInteger(const std::string& num);
};