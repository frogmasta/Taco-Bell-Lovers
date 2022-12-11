#include "graph.h"
#include <cmath>

using namespace std;

vector<float> Graph::PageRank() const
{
    // stores PageRank of each vertex in the graph
    vector<float> ranks(getVertices().size(), 1/ (float) getVertices().size());
    vector<float> previous;

    int n = 0;

    // runs through 100 iterations to bring each PageRank to equilibrium
    while(n < 100)
    {
        previous = ranks;
        for(int i = 0; i < (int) ranks.size(); i++)
        {
            ranks[i] = PageRankHelper(i, previous);
        }

        n++;
    }

    // returns vector containing PageRank of each vertex corresponding to its index
    return ranks;
}

// helper function to calculate PageRank for each vertex in the graph
float Graph::PageRankHelper(int v, const vector<float>& prev) const
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

    for(int i = 0; i < (int) numEdges.size(); i++)
    {
        cout << numEdges[i] << endl;
    }

    //cout << "siu" << endl;

    float rank = 0; // stores final PageRank of vertex at the end of the iteration

    for(int i = 0; i < (int) sourceVertices.size(); i++)
    {
        rank += prev[sourceVertices[i]] / (float) numEdges[i];
    }

    //rank = floor(rank * 1000) / (float) 1000;

    //cout << rank << endl;

    return rank;
}