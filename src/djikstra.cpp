#include "djikstra.h"

using namespace std;

Djikstra::Djikstra(Graph *graph) {
  if (!graph->isEdgeAggregated()) throw invalid_argument("Cannot give non edge aggregated graph to Djikstra's algorithm.");
  _graph = graph;
  adjList = _graph->getAdjList();
}

/**
 * Returns a vector of visited nodes and trust rating from source to destination.
 *
 * @param src source vertex
 * @param dest destination vertex
 * @return vector of ints in ascending order of visited nodes from source
 */
vector<int> Djikstra::findPath(int src, int dest) {
  if (!_graph->vertexExists(src) || !_graph->vertexExists(dest)) throw invalid_argument("Either source or destination vertexes don't exist in the graph.");

  if (src == dest) {
    cout << "Source and destination are the same." << endl;
    return {src};
  }

  vector<int> vset;

  // set all nodes as not visited and distances as infinity
  for (const auto& pair : adjList) {
    dist[pair.first] = -1.0; // -1 is infinite distance
    vset.push_back(pair.first);
  }
  dist[src] = 0; // initialize source as zero

  size_t vsetSize = vset.size();
  while (!vset.empty()) {
    int curr = maxiTrust(vset);
    vset.erase(remove(vset.begin(), vset.end(), curr), vset.end());
    if (vset.size() == vsetSize) {
      cout << "Could not find a possible path to the end vertex" << endl;
      return {};
    }
    vsetSize = vset.size();

    vector<int> neighbors = neighborsInVset(curr, vset);
    for (int neighbor : neighbors) {
      double altDist = dist[curr] + _graph->getEdge(curr, neighbor).weight;
      if (altDist > dist[neighbor]) {
        dist[neighbor] = altDist;
        prev[neighbor] = curr;
      }
    }
  }

  currPathLength = dist[dest];
  stack<int> endToSrc;

  int add = dest;
  while (add != src) {
    endToSrc.push(add);
    add = prev[add];
  }
  endToSrc.push(src);

  vector<int> path;
  while (!endToSrc.empty()) {
    path.push_back(endToSrc.top());
    endToSrc.pop();
  }

  return path;
}


/**
 * Returns the vertex number of the maximum trust distance vertex in a given vertex set
 *
 * @param vset vertex vector to be examined
 * @return vertex number
 */
int Djikstra::maxiTrust(const vector<int> &vset) const {
  double max_trust = 0;
  int ret;

  for (int v : vset) {
    if (dist.at(v) >= max_trust) {
      ret = v;
      max_trust = dist.at(v);
    }
  }

  return ret;
}

/**
 * Gets the neighbors of a node from the graph that also exist in a given vset.
 * Only returns nodes with a non-negative weight
 *
 * @param v vertex to grab neighbors from
 * @param vset vertex set to check with
 * @return vector containing vertex numbers of neighbors that also exist in v
 */
std::vector<int> Djikstra::neighborsInVset(int v, const vector<int> &vset) const {
  vector<int> neighbors = _graph->getNeighbors(v);
  vector<int> ret;

  for (const int& vert : neighbors) {
    if ((find(vset.begin(), vset.end(), vert) != vset.end()) && _graph->getEdge(v, vert).weight >= 0) {
      ret.push_back(vert);
    }
  }

  return ret;
}




