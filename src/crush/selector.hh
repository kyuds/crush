#ifndef CRUSH_SELECTOR_TEMPLATE
#define CRUSH_SELECTOR_TEMPLATE

#include "types.hh"
#include "node.hh"

Node& select(BucketType t, Node& origin, long input, int round);

#endif