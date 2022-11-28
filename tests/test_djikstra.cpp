#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include "parse.h"
#include "djikstra.h"

using namespace std;


/* Graph of 5 vertices with different weights and is completely linear */
TEST_CASE("SimpleGraph1", "[weight=10][djikstra]") {
  string infile = "../data/djikstra/SimpleGraph1.csv";
  Graph* g = Parser::generateGraph(infile, true);

  Djikstra djikstra = Djikstra(g);
  djikstra.findPath(1,5);
  vector<int> path = djikstra.getCurrPath();
  double dist = djikstra.getPathDist();


  vector<int> correctPath{1,2,3,4,5};
  double correctDist = 18.0;

  REQUIRE(path == correctPath);
  REQUIRE(dist == correctDist);

  delete g;
}

/* Graph of 5 vertices with different weights and is completely linear.
 * However, there is a negative edge that exists to the last vertex which will make the graph disconnected.
 * */
TEST_CASE("SimpleGraph2", "[weight=10][djikstra]") {
  string infile = "../data/djikstra/SimpleGraph2.csv";
  Graph* g = Parser::generateGraph(infile, true);

  Djikstra djikstra = Djikstra(g);
  djikstra.findPath(1,4);
  vector<int> path = djikstra.getCurrPath();
  double dist = djikstra.getPathDist();


  vector<int> correctPath{1,2,3,4};
  double correctDist = 12.0;

  REQUIRE(path == correctPath);
  REQUIRE(dist == correctDist);

  delete g;
}


TEST_CASE("BranchedGraphUni", "[weight=10][djikstra]") {
  string infile = "../data/djikstra/BranchedGraphUni.csv";
  Graph* g = Parser::generateGraph(infile, true);

  Djikstra djikstra = Djikstra(g);
  djikstra.findPath(1,8);
  vector<int> path = djikstra.getCurrPath();
  double dist = djikstra.getPathDist();

  vector<int> correctPath{1,2,4,8};
  double correctDist = 21.0;

  REQUIRE(path == correctPath);
  REQUIRE(dist == correctDist);
}