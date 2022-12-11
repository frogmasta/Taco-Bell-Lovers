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

        Edge();
        explicit Edge(int s, int d, double w);

        bool strong_equality(const Edge& other) const;
        bool operator==(const Edge& other) const;
};
