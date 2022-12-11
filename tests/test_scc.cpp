#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include "parse.h"

using namespace std;

/* Simple example with three connected components (also tests .csv files with spaces!) */
TEST_CASE("scc_simple1", "[weight=10][scc]") {
    string infile = "../data/scc_1.csv";
    Graph* g = Parser::generateGraph(infile, true);

    vector<vector<int>> scc = g->StronglyConnectedComponents();

    for (vector<int>& component : scc) {
        sort(component.begin(), component.end());
    }

    vector<int> c1 = vector<int>{0, 1, 2, 3};
    vector<int> c2 = vector<int>{4, 5, 6};
    vector<int> c3 = vector<int>{7};

    REQUIRE(scc.size() == 3);

    REQUIRE(find(scc.begin(), scc.end(), c1) != scc.end());
    REQUIRE(find(scc.begin(), scc.end(), c2) != scc.end());
    REQUIRE(find(scc.begin(), scc.end(), c3) != scc.end());
}

/* Another simple example with three connected components */
TEST_CASE("scc_simple2", "[weight=10][scc]") {
    string infile = "../data/scc_2.csv";
    Graph* g = Parser::generateGraph(infile, true);

    vector<vector<int>> scc = g->StronglyConnectedComponents();

    for (vector<int>& component : scc) {
        sort(component.begin(), component.end());
    }

    vector<int> c1 = vector<int>{0, 1, 2, 3};
    vector<int> c2 = vector<int>{4};
    vector<int> c3 = vector<int>{5};

    REQUIRE(scc.size() == 3);

    REQUIRE(find(scc.begin(), scc.end(), c1) != scc.end());
    REQUIRE(find(scc.begin(), scc.end(), c2) != scc.end());
    REQUIRE(find(scc.begin(), scc.end(), c3) != scc.end());
}

/* Running scc on a graph produced for another test case */
TEST_CASE("scc_hard1", "[weight=10][scc]") {
    string infile = "../data/bfs.csv";
    Graph* g = Parser::generateGraph(infile, true);

    vector<vector<int>> scc = g->StronglyConnectedComponents();

    for (vector<int>& component : scc) {
        sort(component.begin(), component.end());
    }

    vector<int> c1 = vector<int>{1};
    vector<int> c2 = vector<int>{4};
    vector<int> c3 = vector<int>{7};
    vector<int> c4 = vector<int>{2, 5, 6};
    vector<int> c5 = vector<int>{3};
    vector<int> c6 = vector<int>{10, 11, 12};

    REQUIRE(scc.size() == 6);

    REQUIRE(find(scc.begin(), scc.end(), c1) != scc.end());
    REQUIRE(find(scc.begin(), scc.end(), c2) != scc.end());
    REQUIRE(find(scc.begin(), scc.end(), c3) != scc.end());
    REQUIRE(find(scc.begin(), scc.end(), c4) != scc.end());
    REQUIRE(find(scc.begin(), scc.end(), c5) != scc.end());
    REQUIRE(find(scc.begin(), scc.end(), c6) != scc.end());
}