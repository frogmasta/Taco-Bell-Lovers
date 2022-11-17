#pragma once

#include "graph.h"
#include "edge.h"

class Djikstra {
 public:
  explicit Djikstra(Graph* graph) : _graph(graph) {};
  std::vector<Edge> findPath(int v1, int v2);
 private:
  [[maybe_unused]] Graph* _graph;
};