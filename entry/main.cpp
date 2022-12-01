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
    std::string dataset = "soc-sign-bitcoinotc.csv";
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

    // strongly connected components
    std::vector<std::vector<int>> scc = g->StronglyConnectedComponents();
    for (const std::vector<int>& component : scc) {
        std::cout << "Component: ";
        for (const int& node : component) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    // djikstra
    Djikstra djikstra(g);
    try {
        djikstra.findPath(1, 5098);
        std::vector<int> path = djikstra.getCurrPath();
        std::cout << std::endl;
        std::cout << "Path trust length: " << djikstra.getPathDist() << std::endl;
        std::cout << std::endl;
        djikstra.printCurrPath();
    } catch(const std::invalid_argument& ia) {
        std::cout << "Path listed doesn't exist in the graph." << std::endl;
    }

    delete g;
    return 0;
}