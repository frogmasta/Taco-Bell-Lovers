#include <iostream>
#include <vector>

#include "parse.h"
#include "graph.h"
#include "edge.h"

/**
 * Driver file for the final project.
 * 
 * @todo command-line arguments for which .csv file to parse
 */
int main() {
    /* Tester to check parsing */
    std::string fname = "../data/soc-sign-bitcoinotc.csv";
    Parser* p = new Parser();
    Graph* g = p->generateGraph(fname);
    g->printGraph();

    delete p;
    delete g;

    return 0;
}