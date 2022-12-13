#include "graph.h"
#include <cmath>
#include <utility>

using namespace std;

unordered_map<int, double> Graph::PageRank() const
{
    // stores PageRank of each vertex in the graph
    vector<int> verts = getVertices();
    unordered_map<int, double> ranks;

    for(int i = 0; i < (int) verts.size(); i++)
    {
        ranks.insert(make_pair(verts[i], 1 / (double) verts.size()));
    }

    int n = 0;

    // runs through 10 iterations to bring each PageRank to equilibrium
    while(n < 100)
    {
        unordered_map<int, double> previous;
        previous.insert(ranks.begin(), ranks.end());
        for(pair<int, double> p : ranks)
        {
            ranks.at(p.first) = PageRankHelper(p.first, previous);
        }

        n++;
    }

    // returns unordered map containing PageRank of each vertex corresponding to its index
    return ranks;
}

// helper function to calculate PageRank for each vertex in the graph
double Graph::PageRankHelper(int v, const unordered_map<int, double>& prev) const
{

    vector<int> vertices = getVertices();
    vector<int> sourceVertices; // contains every vertex with a edge pointed to the passed vertex
    vector<int> numEdges;


    for(int i = 0; i < (int) vertices.size(); i++)
    {
        vector<Edge> edges = getEdges(vertices[i]);
        for(int j = 0; j < (int) edges.size(); j++)
        {
            if(edges[j].dest == v)
            {
                sourceVertices.push_back(vertices[i]);
                numEdges.push_back((int) edges.size());
            }
        }
    }

    double rank = 0; // stores final PageRank of vertex at the end of the iteration

    for(int i = 0; i < (int) sourceVertices.size(); i++)
    {
        rank += prev.at(sourceVertices[i]) / (double) numEdges[i];
    }

    vector<Edge> outgoingEdges = getEdges(v);

    if((int) outgoingEdges.size() == 0)
    {
        rank += prev.at(v);
    }

    return rank;
}
