#include "graph.h"
#include <cmath>

using namespace std;

unordered_map<int, double> Graph::PageRank() const
{
    // stores PageRank of each vertex in the graph
    vector<int> verts = getVertices();
    vector<double> ranks(getVertices().size(), 1/ (double) getVertices().size());
    vector<double> previous;

    int n = 0;

    // runs through 100 iterations to bring each PageRank to equilibrium
    while(n < 100)
    {
        previous = ranks;
        for(int i = 0; i < (int) ranks.size(); i++)
        {
            ranks[i] = PageRankHelper(verts[i], previous);
        }

        n++;
    }

    unordered_map<int, double> mappedRanks;

    for(int i = 0; i < (int) ranks.size(); i++)
    {
        mappedRanks.insert(make_pair(verts[i], ranks[i]));
    }

    // returns unordered map containing PageRank of each vertex corresponding to its index
    return mappedRanks;
}

// helper function to calculate PageRank for each vertex in the graph
double Graph::PageRankHelper(int v, const vector<double>& prev) const
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
        rank += prev[sourceVertices[i]] / (double) numEdges[i];
    }

    return rank;
}
