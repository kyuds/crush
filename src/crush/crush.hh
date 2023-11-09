#ifndef CRUSH_ALGO
#define CRUSH_ALGO

#include <vector>

#include "types.hh"
#include "node.hh"

std::vector<Node*> select(Node * root, long input, int count, NodeType t, bool first_n);

#endif