#pragma once

/*
 * Simple edge class to help graph structure
 */
class Edge {
    public:
        int source;
        int dest;
        int weight;

        Edge();
        Edge(int s, int d, int w);

        bool operator==(Edge& other) const;
};