#pragma once

/*
 * Simple edge class
 */
class Edge {
    public:
        int source = -1;
        int dest = -1;
        double weight = 0;

        int aggregation_count = 0;

        Edge() = default;
        Edge(int s, int d, int w);

        bool operator==(Edge& other) const;
};