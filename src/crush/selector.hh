#ifndef CRUSH_SELECTOR
#define CRUSH_SELECTOR

#include "types.hh"
#include "node.hh"

Node* select_uniform(Node* origin, long input, int round);
Node* select_list(Node* origin, long input, int round);
Node* select_tree(Node* origin, long input, int round);
Node* select_straw(Node* origin, long input, int round);

#endif