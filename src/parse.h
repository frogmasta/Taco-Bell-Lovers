#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "graph.h"

/* Class to render the csv files into workable graphs */
class Parser {
    private:
        /* EdgeInfo interface */
        struct EdgeInfo{
            EdgeInfo(int s, int d, int w) {
                source = s;
                dest = d;
                weight = w;
            }

            int source;
            int dest;
            int weight;
        };

    public:
        Parser();

        std::vector<EdgeInfo> readFile(std::string fname);
        Graph* generateGraph(std::string fname);
    private:

};