#ifndef CRUSH_TYPES
#define CRUSH_TYPES

// This is static as described in 
// the original paper.
enum BucketType {
    UNIFORM,
    LIST,
    TREE,
    STRAW
};

// This is subject to change based
// on cluster configurations. Root
// is the only mandatory type that
// is going to determine the root
// of the cluster. 
enum NodeType {
    ROOT,
    ROW,
    CABINET,
    DISK
};

#endif