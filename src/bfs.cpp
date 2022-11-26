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
    queue<int> q;
    q.push(v);
    labeling.at(v) = true;

    while(!q.empty()) {
        int currVertex = q.front();
        traversal.push_back(currVertex);
        q.pop();

        for (const Edge& e : getEdges(currVertex)) {
            if (labeling.at(e.dest) == false) {
                q.push(e.dest);
                labeling.at(e.dest) = true;
            }
        }
    }
}

/**
 * Returns an iterative BFS traversal of the graph. If the graph isn't connected, it traverses the connected component first.
 *
 * @param v starting vertex
 * @return visited nodes in order
 */
vector<int> Graph::bfs(int v) const {
    if (!vertexExists(v)) return vector<int>();

    unordered_map<int, bool> labeling;
    vector<int> vertices = getVertices();
    for (int& ver : getVertices()) {
        labeling.insert({ver, false});

        // Have starting vertex at the front, so we explore it's connected component first
        if (ver == v) swap(ver, vertices.at(0));  
    }

    vector<int> traversal({});
    int curridx = 0;
    while(traversal.size() < vertices.size()) {
        while(labeling.at(vertices[curridx]) == true) {
            ++curridx;
        }

        bfs_helper(vertices[curridx], traversal, labeling);
    }

    return traversal;
}