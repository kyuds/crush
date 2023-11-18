#include "selector.hh"

#include <stdexcept>
#include <vector>

Node* select_uniform(Node* origin, long input, int round) {
    throw std::invalid_argument("Uniform selector not implemented yet.");
}

Node* select_list(Node* origin, long input, int round) {
    throw std::invalid_argument("List selector not implemented yet.");
}

Node* select_tree(Node* origin, long input, int round) {
    throw std::invalid_argument("Tree selector not implemented yet.");
}

Node* select_straw(Node* origin, long input, int round) {
    throw std::invalid_argument("Straw selector not implemented yet.");
}