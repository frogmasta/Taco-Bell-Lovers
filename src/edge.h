#pragma once

/*
 * Simple edge class
 */
class Edge {
    public:
        int source;
        int dest;
        double weight;

        int aggregation_count;

        explicit Edge(int s, int d, int w);

        bool operator==(Edge& other) const;
};
