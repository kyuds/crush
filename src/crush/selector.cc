#include "selector.hh"

#include <stdexcept>

Node& select(Node& origin, long input, int round) {
    switch(origin.getBucketType()) {
        case UNIFORM:
            break;
        case LIST: 
            break;
        case TREE:
            break;
        case STRAW:
            break;
        default:
            throw std::invalid_argument("BucketType doesn't match any defined value.");
    }
}
