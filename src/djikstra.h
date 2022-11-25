#pragma once

#include "graph.h"
#include "edge.h"
#include <map>
#include <stdexcept>
#include <iostream>
#include <stack>

class Djikstra {
 public:
  explicit Djikstra(Graph* graph);
  std::vector<int> findPath(int src, int dest);
  double getPathDist() const {return currPathLength;};

 private:
  int maxiTrust(const std::vector<int>& vset) const;
  std::vector<int> neighborsInVset(int v, const std::vector<int> &vset) const;

  // key = vertex number : value = distance
  std::unordered_map<int, double> dist;
  std::unordered_map<int, int> prev;

  std::unordered_map<int, std::vector<Edge>> adjList;
  Graph* _graph;

  double currPathLength{0};
  std::vector<int> currPath{};
};