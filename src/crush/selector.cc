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

// Node& select_uniform(Node& origin, long input, int round) {

// }

// Node& select_list(Node& origin, long input, int round) {
    
// }

// Node& select_tree(Node& origin, long input, int round) {
    
// }

// Node& select_straw(Node& origin, long input, int round) {
    
// }