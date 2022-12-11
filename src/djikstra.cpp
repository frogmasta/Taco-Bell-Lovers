#include "djikstra.h"

using namespace std;

const double MAX_RATING = 10;

Djikstra::Djikstra(Graph *graph) {
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
void Djikstra::findPath(int src, int dest) {
  Graph reconstructed = reconstructGraph(src); // Ensures we are working with a fully connected graph

  if (!reconstructed.vertexExists(src) || !reconstructed.vertexExists(dest)) throw invalid_argument("Either source or destination vertexes don't exist in the graph.");

  if (src == dest) {
    cout << "Source and destination are the same." << endl;
    return;
  }

  vector<int> vset;

  // set all nodes as not visited and distances as infinity
  for (const auto& pair : reconstructed.getAdjList()) {
    dist[pair.first] = numeric_limits<double>::max(); // -infinite distance
    vset.push_back(pair.first);
  }
  dist[src] = 0; // initialize source as zero

  size_t vsetSize = vset.size();
  while (!vset.empty()) {
    int curr = miniTrust(vset);
    vset.erase(remove(vset.begin(), vset.end(), curr), vset.end());
    if (vset.size() == vsetSize) {
      cout << "Could not find a possible path to the end vertex" << endl;
      return;
    }
    vsetSize = vset.size();

    vector<int> neighbors = neighborsInVset(curr, vset, reconstructed);
    for (int neighbor : neighbors) {
      double altDist = dist[curr] + reconstructed.getEdge(curr, neighbor).weight;
      if (altDist < dist[neighbor]) {
        dist[neighbor] = altDist;
        prev[neighbor] = curr;
      }
    }
  }

  // Now we need to trace back prev to construct the nodes involved in the path
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

  currPathLength = -1 * (dist[dest] - MAX_RATING * ((double) path.size()-1));

  currPath = path;
}

/**
 * Prints out the nodes in the strongest trust path
 */
void Djikstra::printCurrPath() const {
  cout << "Djikstra's path from vertex " << currPath.at(0) << " to vertex " << currPath.at(currPath.size()-1) << "." << endl;
  for (unsigned long i = 0; i < currPath.size(); i++) {
    cout << "Node " << i << ": " << currPath.at(i) << endl;
  }
}

/**
 * Returns the vertex number of the minimum (in reality the maximum) trust distance vertex in a given vertex set
 *
 * @param vset vertex vector to be examined
 * @return vertex number
 */
int Djikstra::miniTrust(const vector<int> &vset) const {
  double min_trust = dist.at(vset.at(0));
  int ret = vset.at(0); // should not through an error since vset is supposed to not be empty when this is called

  for (int v : vset) {
    if (dist.at(v) < min_trust) {
      ret = v;
      min_trust = dist.at(v);
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
std::vector<int> Djikstra::neighborsInVset(int v, const vector<int> &vset, const Graph& graph) {
  vector<int> neighbors = graph.getNeighbors(v);
  vector<int> ret;

  for (const int& vert : neighbors) {
    if ((find(vset.begin(), vset.end(), vert) != vset.end()) && graph.getEdge(v, vert).weight >= 0) {
      ret.push_back(vert);
    }
  }

  return ret;
}

/**
 * Private helper function to reconstruct a graph starting from the source using BFS so it is fully connected.
 *
 * @param v vertex to begin BFS search from
 * @return Reconstructed graph that is now fully connected
 */
Graph Djikstra::reconstructGraph(int v) const {
  Graph ret{};
  set<int> visited;

  queue<int> q;
  q.push(v);
  visited.insert(v);
  ret.addVertex(v);

  while(!q.empty()) {
    int currVertex = q.front();
    ret.addVertex(currVertex);
    q.pop();

    for (const Edge& e : _graph->getEdges(currVertex)) {
      // add outgoing edge if we can
      if (e.weight > 0) {
        ret.addEdge(e.source, e.dest, MAX_RATING - e.weight, false);
      } else {
        continue;
      }

      // add destination if we haven't visited it yet
      if (visited.count(e.dest) == 0) {
        q.push(e.dest);
        visited.insert(e.dest);
      }
    }
  }

  return ret;
}