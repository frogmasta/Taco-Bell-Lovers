#include "graph.h"

using std::vector;
using std::unordered_map;
using std::queue;
using std::swap;

/** 
 * Helper function for BFS traversal. 
 * 
 * @param v beginning vertex to start searching
 * @param traversal current status of the traversal
 * @param labeling current labeling of the vertices in the graph
 */
void Graph::bfs_helper(int v, vector<int>& traversal, unordered_map<int, bool>& labeling) const {
    /* Initialization */
    queue<int> q;
    q.push(v);
    labeling.at(v) = true;

    /* BFS traversal with a queue */
    while(!q.empty()) {
        /* Visit current node */
        int currVertex = q.front();
        traversal.push_back(currVertex);
        q.pop();

        /* Check all the edges for un-visited nodes */
        for (const Edge& e : getEdges(currVertex)) {
            if (labeling.at(e.dest) == false) {
                q.push(e.dest);
                labeling.at(e.dest) = true;
            }
        }
    }
}

/**
 * Returns an iterative BFS traversal of the graph. If the graph is connected, it traverses the connected component first.
 *
 * @param v starting vertex
 * @return visited nodes in order
 */
vector<int> Graph::bfs(int v) const {
    /* If v doesn't exist, we return an empty traversal */
    if (!vertexExists(v)) return vector<int>();

    /* Initialization */
    unordered_map<int, bool> labeling;
    vector<int> vertices = getVertices();
    for (int& ver : getVertices()) {
        /* Label vertices as unexplored */
        labeling.insert({ver, false});
        if (ver == v) swap(ver, vertices.at(0));
    }

    /* BFS traversal */
    vector<int> traversal({});
    int curridx = 0;
    while(traversal.size() < vertices.size()) {
        /* Find next un-visited vertex */
        while(labeling.at(vertices[curridx]) == true) {
            ++curridx;
        }

        /* BFS traversal on current vertex */
        bfs_helper(vertices[curridx], traversal, labeling);
    }

    /* Return completed traversal */
    return traversal;
}