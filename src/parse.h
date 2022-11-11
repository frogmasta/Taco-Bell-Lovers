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

        std::vector<Edge> readFile(std::string fname);
        Graph* generateGraph(std::string fname);
    private:
};