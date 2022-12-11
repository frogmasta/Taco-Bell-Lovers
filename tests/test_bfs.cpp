#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include "parse.h"

using namespace std;


/* Graph where there's only a single, clear path to traverse */
TEST_CASE("simpleGraph", "[weight=10][bfs]") {
    string infile = "../data/scc_1.csv";
    Graph* g = Parser::generateGraph(infile, true);

    vector<int> path = g->bfs(3);
    vector<int> correctPath{3, 0, 1, 2, 4, 5, 6, 7};

    REQUIRE(path.size() == 8);
    REQUIRE(path == correctPath);

    delete g;
}

/* Non-simple, connected graph */
TEST_CASE("simpleGraph2", "[weight=10][bfs]") {
    string infile = "../data/test1.csv";
    Graph* g = Parser::generateGraph(infile, true);

    vector<int> path = g->bfs(1);
    vector<int> correctPath = {1, 2, 3, 4, 5};

    REQUIRE(path.size() == 5);
    REQUIRE(path == correctPath);

    delete g;
}