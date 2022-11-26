#include "edge.h"

/* do nothing, but DON'T DELETE */
Edge::Edge() = default;

/* Paramaterized constructor */
Edge::Edge(int s, int d, int w) {
    source = s;
    dest = d;
    weight = w;
    aggregation_count = 1;
}

/**
 * Checks for source/destination equality. **DOES NOT** check for weight equality!
 *
 * @param edge to compare against
 * @return true if equal, false otherwise
 */
bool Edge::operator==(Edge& other) const {
    return (source == other.source && dest == other.dest);
}