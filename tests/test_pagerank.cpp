#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include "parse.h"
#include <cmath>

using namespace std;


TEST_CASE("pageTest1", "[weight=10]") {
    string infile = "../data/pageTest1.csv";
    Graph* g = Parser::generateGraph(infile, true);

    unordered_map<int, double> ranks = g->PageRank();

    double rank0 = ranks.at(0);
    double rank1 = ranks.at(1);
    double rank2 = ranks.at(2);
    double rank3 = ranks.at(3);

    rank0 = floor(rank0*1000+0.5)/1000;
    rank1 = floor(rank1*10000+0.5)/10000;
    rank2 = floor(rank2*1000+0.5)/1000;
    rank3 = floor(rank3*10000+0.5)/10000;

    REQUIRE(rank0 == 0.125);
    REQUIRE(rank1 == 0.1875);
    REQUIRE(rank2 == 0.375);
    REQUIRE(rank3 == 0.3125);
}

TEST_CASE("pageTest2", "[weight=10]") {
    string infile = "../data/pageTest2.csv";
    Graph* g = Parser::generateGraph(infile, true);

    unordered_map<int, double> ranks = g->PageRank();

    double rank0 = ranks.at(0);
    double rank1 = ranks.at(1);
    double rank2 = ranks.at(2);

    if(rank0 < 0.00001)
    {
        rank0 = 0;
    }

    if(rank1 < 0.00001)
    {
        rank1 = 0;
    }

    if(rank2 < 0.00001)
    {
        rank2 = 0;
    }

    rank0 = floor(rank0*1000+0.5)/1000;
    rank1 = floor(rank1*1000+0.5)/1000;
    rank2 = floor(rank2*1000+0.5)/1000;

    REQUIRE(rank0 == 0);
    REQUIRE(rank1 == 0);
    REQUIRE(rank2 == 1);
}