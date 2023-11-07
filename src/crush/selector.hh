#ifndef CRUSH_SELECTOR_TEMPLATE
#define CRUSH_SELECTOR_TEMPLATE

#include "common.hh"
#include "node.hh"

Node& select(BucketType t, long input, int round);

#endif