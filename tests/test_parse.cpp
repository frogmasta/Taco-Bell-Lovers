/*
#include <catch2/catch_test_macros.hpp>

#include "graph.cpp"
#include "parse.cpp"

using std::string;
using std::vector;

*/
/* Tests base functionality, no edge weights, no incorrect inputs *//*

TEST_CASE("simpleGraph1", "[weight=10]") {
    string infile = "../data/bfs.csv";
    Graph* g = Parser::generateGraph(infile, true);

    vector<int> vertices = g->getVertices();
    std::sort(vertices.begin(), vertices.end());
    REQUIRE(vertices == vector<int>{1, 2, 3, 4, 5, 6, 7, 10, 11, 12});

    vector<Edge> adj1 = g->getEdges(1);
    vector<Edge> adj2 = g->getEdges(2);
    vector<Edge> adj4 = g->getEdges(4);
    vector<Edge> adj5 = g->getEdges(5);
    vector<Edge> adj6 = g->getEdges(6);
    vector<Edge> adj10 = g->getEdges(10);
    vector<Edge> adj11 = g->getEdges(11);
    vector<Edge> adj12 = g->getEdges(12);

    REQUIRE(adj1.size() + adj2.size() + adj4.size() + adj5.size() + adj6.size() + adj10.size() + adj11.size() + adj12.size() == 10);

    REQUIRE(std::find(adj1.begin(), adj1.end(), Edge(1, 4, 0)) != adj1.end());

    REQUIRE(std::find(adj2.begin(), adj2.end(), Edge(2, 6, 0)) != adj2.end());

    REQUIRE(std::find(adj4.begin(), adj4.end(), Edge(4, 7, 0)) != adj4.end());
    REQUIRE(std::find(adj4.begin(), adj4.end(), Edge(4, 2, 0)) != adj4.end());

    REQUIRE(std::find(adj5.begin(), adj5.end(), Edge(5, 2, 0)) != adj5.end());

    REQUIRE(std::find(adj6.begin(), adj6.end(), Edge(6, 5, 0)) != adj6.end());
    REQUIRE(std::find(adj6.begin(), adj6.end(), Edge(6, 3, 0)) != adj6.end());

    REQUIRE(std::find(adj10.begin(), adj10.end(), Edge(10, 11, 0)) != adj10.end());
    REQUIRE(std::find(adj11.begin(), adj11.end(), Edge(11, 12, 0)) != adj11.end());
    REQUIRE(std::find(adj12.begin(), adj12.end(), Edge(12, 10, 0)) != adj12.end());

    delete g;
}

*/
/* Tests graph parsing, handling incorrect inputs, AND edge compression! *//*

TEST_CASE("hardGraph1", "[weight=10]") {
    string infile = "../data/test1.csv";
    Graph* g = Parser::generateGraph(infile, true);

    vector<int> vertices = g->getVertices();
    std::sort(vertices.begin(), vertices.end());
    REQUIRE(vertices == vector<int>{1, 2, 3, 4, 5});

    vector<Edge> adj1 = g->getEdges(1);
    vector<Edge> adj2 = g->getEdges(2);
    vector<Edge> adj3 = g->getEdges(3);
    vector<Edge> adj4 = g->getEdges(4);
    vector<Edge> adj5 = g->getEdges(5);

    REQUIRE(adj1.size() + adj2.size() + adj3.size() + adj4.size() + adj5.size() == 7);

    auto edge1 = std::find(adj1.begin(), adj1.end(), Edge(1, 2, 10));
    REQUIRE((edge1 != adj1.end() && edge1->strong_equality(Edge(1, 2, 10))));
    auto edge2 = std::find(adj1.begin(), adj1.end(), Edge(1, 3, 14.0/3.0));
    REQUIRE((edge2 != adj1.end() && edge2->strong_equality(Edge(1, 3, 14.0/3.0))));

    auto edge3 = std::find(adj2.begin(), adj2.end(), Edge(2, 1, 2));
    REQUIRE((edge3 != adj2.end() && edge3->strong_equality(Edge(2, 1, 2))));

    auto edge4 = std::find(adj3.begin(), adj3.end(), Edge(3, 4, -2));
    REQUIRE((edge4 != adj3.end() && edge4->strong_equality(Edge(3, 4, -2))));

    auto edge5 = std::find(adj4.begin(), adj4.end(), Edge(4, 1, -5));
    REQUIRE((edge5 != adj4.end() && edge5->strong_equality(Edge(4, 1, -5))));
    auto edge6 = std::find(adj4.begin(), adj4.end(), Edge(4, 5, 0));
    REQUIRE((edge6 != adj4.end() && edge6->strong_equality(Edge(4, 5, 0))));

    auto edge7 = std::find(adj5.begin(), adj5.end(), Edge(5, 3, 7));
    REQUIRE((edge7 != adj5.end() && edge7->strong_equality(Edge(5, 3, 7))));

    delete g;
}*/
