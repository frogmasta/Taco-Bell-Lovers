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
    std::string fname = "../data/test1.csv";
    Parser* p = new Parser();
    Graph* g = Parser::generateGraph(fname, true);
    g->printGraph();

    delete p;
    delete g;

    return 0;
}