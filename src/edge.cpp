#include "edge.h"

/* do nothing, but DON'T DELETE */
Edge::Edge() = default;

/* Paramaterized constructor */
Edge::Edge(int s, int d, double w) {
    source = s;
    dest = d;
    weight = w;
    aggregation_count = 1;
}

/**
 * Checks for STRONG equality (i.e. also the edge weight).
 *
 * @param edge to compare against
 * @return true if equal, false otherwise
 */
bool Edge::strong_equality(const Edge& other) const {
    return source == other.source && dest == other.dest && weight == other.weight;
}

/**
 * Checks for source/destination equality. **DOES NOT** check for weight equality!
 *
 * @param edge to compare against
 * @return true if equal, false otherwise
 */
bool Edge::operator==(const Edge& other) const {
    return source == other.source && dest == other.dest;
}