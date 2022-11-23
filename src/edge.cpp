#include "edge.h"

Edge::Edge() { /* do nothing */}

/*
 * Paramaterized constructor for edge
 */
Edge::Edge(int s, int d, int w) {
    source = s;
    dest = d;
    weight = w;
}

/**
 * Checks for source/destination equality. DOES NOT check for weight equality!
 *
 * @param edge to compare against
 * @return true if equal, false otherwise
 */
bool Edge::operator==(Edge& other) const {
    return (source == other.source && dest == other.dest);
}