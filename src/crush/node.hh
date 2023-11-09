#ifndef CRUSH_NODE_TEMPLATE
#define CRUSH_NODE_TEMPLATE

#include <string>
#include <vector>

#include "types.hh"

// abstract class to represent a node on the cluster.
// this class should be implemented with additional 
// methods to define the cluster map, etc, but these
// methods are the bare minimum necessary to navigate
// through the cluster.
class Node {
    public:
        virtual ~Node() {}
        virtual BucketType getBucketType() = 0;
        virtual NodeType getNodeType() = 0;
        virtual std::string getId() = 0;
        virtual int getWeight() = 0;
        virtual bool failed() = 0;
        virtual bool overloaded() = 0;
        virtual bool isLeaf() = 0;
        virtual Node* parent() = 0;
        virtual std::vector<Node*> children() = 0;
};

#endif