#include <iostream>
#include <vector>

#include "parse.h"
#include "graph.h"
#include "edge.h"
#include "djikstra.h"

/**
 * Driver file for the final project. Takes a command line input to which file to analyze. Defaults to bitcoin dataset.
 */
int main(int argc, char **argv) {
    std::string dataset = "test2.csv";
    if (argc > 1) dataset = argv[1];

    std::string fname = "../data/" + dataset;
    std::cout << "The input file is: " << fname << std::endl;
    Graph* g = Parser::generateGraph(fname, true);

    if (g == nullptr) {
        std::cout << "An error has occured when reading the input file you've specified. ";
        std::cout << "Either the .csv file was unable to be opened, or you provided an empty graph." << std::endl;
        return 0;
    }

    g->printGraph();

    Djikstra djikstra(g);
    std::vector<int> path = djikstra.findPath(1, 4);
    std::cout << djikstra.getPathDist() << std::endl;

//
//    std::cout << "BFS Traversal: ";
//    for (const int& v : g->bfs(1)) {
//        std::cout << v << " ";
//    }
//    std::cout << std::endl;

    delete g;
    return 0;
}