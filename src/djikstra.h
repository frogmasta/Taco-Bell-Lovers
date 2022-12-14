#pragma once

#include "graph.h"
#include "edge.h"
#include <map>
#include <stdexcept>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <limits>
#include <fstream>

class Djikstra {
 public:
  explicit Djikstra(Graph* graph);
  void findPath(int src, int dest);
  double getPathDist() const {return currPathLength;};
  std::vector<int> getCurrPath() const {return currPath;};
  void printCurrPath(std::string fname) const;
  void printCurrPath() const;

 private:
  int miniTrust(const std::vector<int>& vset) const;
  static std::vector<int> neighborsInVset(int v, const std::vector<int> &vset, const Graph& graph) ;
  Graph reconstructGraph(int v) const;
  void traceBackPath() const;

  // key = vertex number : value = distance
  std::unordered_map<int, double> dist;
  std::unordered_map<int, int> prev;

  std::unordered_map<int, std::vector<Edge>> adjList;
  Graph* _graph;

  double currPathLength{0};
  std::vector<int> currPath{};
};