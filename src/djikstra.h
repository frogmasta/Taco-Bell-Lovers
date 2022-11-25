#pragma once

#include "graph.h"
#include "edge.h"
#include <map>
#include <utility>

class Djikstra {
 public:
  explicit Djikstra(Graph* graph);
  std::vector<Edge> findPath(int v1, int v2);
 private:
  Graph* _graph;
};