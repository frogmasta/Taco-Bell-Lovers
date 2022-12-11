#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


#include "parse.h"
#include "graph.h"
#include "edge.h"
#include "djikstra.h"

/**
 * Runs Dijkstra's algorithm and produces an output.
 */
void runDijkstra(Graph* g, int startingNode, int endingNode) {
    Djikstra djikstra(g);
    try {
        djikstra.findPath(startingNode, endingNode);
        std::vector<int> path = djikstra.getCurrPath();
        djikstra.printCurrPath("dijkstra_out.txt");
    } catch(const std::invalid_argument& ia) {
        std::cout << "Path listed doesn't exist in the graph." << std::endl;
        return;
    }

    std::cout << "Results of Dijkstra's have been written to \"dijkstra_out.txt\"" << std::endl;
}

/**
 * Runs Strongly Connected Components and produces an output.
 */
void runSCC(Graph* g, int cutoffWeight) {
    std::vector<std::vector<int>> scc = g->StronglyConnectedComponents(cutoffWeight);
    std::ofstream outfile("scc_out.txt");

    size_t i = 0;
    outfile << "List of connected components of size greater than 1 (size 1 components are trivial)" << std::endl;
    for (const std::vector<int>& component : scc) {
        if (component.size() < 2) continue;

        outfile << "Component: ";

        for (const int& node : component) {
            outfile << node << " ";
        }

        outfile << std::endl;
        ++i;
    }

    std::cout << "Results of SCC have been written to \"scc_out.txt\"" << std::endl;
    outfile.close();
}

/**
 * Runs BFS traversal and produces an output.
 */
void runBFS(Graph* g, int startingNode) {
    std::vector<int> traversal = g->bfs(startingNode);
    if (traversal.empty()) {
        std::cout << "Either you provided an empty graph or the starting vertex was invalid." << std::endl;
        return;
    }

    std::ofstream outfile("bfs_out.txt");

    outfile << "BFS Traversal: " << std::endl;
    for (const int& v : traversal) {
        outfile << v << std::endl;
    }

    std::cout << "Results of BFS have been written to \"bfs_out.txt\"" << std::endl;
    outfile.close();
}

/**
 * Runs PageRank algorithm and produces an output.
 */
void runPagerank(Graph* g) {
    std::unordered_map<int, double> weights = g->PageRank();

    if (weights.empty()) {
        std::cout << "You have provided an empty graph or something else has occured." << std::endl;
        return;
    }

    std::cout << "PageRank: " << std::endl;
    for (const std::pair<int, double> p : weights) {
        std::cout << p.first << ": " << p.second << "%" << std::endl;
    }
}

/**
 * Driver file for the final project. Takes a command line input to which file to analyze. Defaults to bitcoin dataset.
 */
int main(int argc, char **argv) {
    std::string dataset = "soc-sign-bitcoinotc.csv";
    std::string algorithm = "";

    int startingNode, endingNode, cutoffWeight;

    if (argc > 1) {
        algorithm = argv[1];
        if (algorithm != "dijkstra" && algorithm != "scc" && algorithm != "bfs" && algorithm != "pagerank") {
            std::cout << "The algorithm you've specific is not valid. Only the following are accepted: dijkstra, scc, bfs, pagerank" << std::endl;
            return 0;
        }
    }

    if (algorithm == "dijkstra") {
        if (argc < 4) {
            std::cout << "Didn't specify starting and/or ending points." << std::endl;
            return 0;
        }

        startingNode = std::stoi(argv[2]);
        endingNode = std::stoi(argv[3]);

        if (argc > 4) dataset = argv[4];
    }

    else if (algorithm == "scc") {
        if (argc < 3) {
            std::cout << "Didn't specify the cutoff weight for SCC. Cutoff weight should be between -10 and 10." << std::endl;
            return 0;
        }

        cutoffWeight = std::stoi(argv[2]);
        if (argc > 3) dataset = argv[3];
    }

    else if (algorithm == "bfs") {
        if (argc < 3) {
            std::cout << "Didn't specify the starting node to begin at." << std::endl;
            return 0;
        }

        startingNode = std::stoi(argv[2]);
        if (argc > 3) dataset = argv[3];
    }

    else if (algorithm == "pagerank") {
        if (argc > 2) dataset = argv[2];
    }

    std::string fname = "../data/" + dataset;
    std::cout << "The specified input file is: " << fname << std::endl;
    Graph* g = Parser::generateGraph(fname, true);

    if (g == nullptr) {
        std::cout << "An error has occured when reading the input file you've specified. ";
        std::cout << "Either the .csv file was unable to be opened, or you provided an empty graph." << std::endl;
        return 0;
    }

    if (algorithm == "dijkstra") {
        runDijkstra(g, startingNode, endingNode);
    }

    else if (algorithm == "scc") {
        runSCC(g, cutoffWeight);
    }

    else if (algorithm == "bfs") {
        runBFS(g, startingNode);
    }

    else if (algorithm == "pagerank") {
        runPagerank(g);
    }

    else {
        runDijkstra(g, 1, 5098);
        runSCC(g, 8);
        runBFS(g, 1);
        runPagerank(g);
    }

    delete g;
    return 0;
}