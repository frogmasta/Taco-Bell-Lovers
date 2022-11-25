#include "edge.h"
#include <iostream>

/* do nothing */
Edge::Edge() = default;


Edge::Edge(int s, int d, double w) {
    source = s;
    dest = d;
    weight = w;
    aggregation_count = 1;
}

/**
 * Checks for source/destination equality. **DOES NOT** check for weight equality!
 *
 * @param other edge to compare against
 * @return true if equal, false otherwise
 */
bool Edge::operator==(const Edge& other) const {
    return (source == other.source && dest == other.dest);
}

/**
 * Checks for STRONG equality (source, destination, and weight).
 *
 * @param other edge to compare against
 * @return true if equal, false otherwise
 */
bool Edge::strong_equality(const Edge& other) const {
    return (source == other.source && dest == other.dest && weight == other.weight);
}