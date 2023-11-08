#ifndef CRUSH_TEST_NODE
#define CRUSH_TEST_NODE

#include <string>
#include <vector>

#include "crush/node.hh"
#include "crush/types.hh"

class TestNode : public Node {
    public:
        TestNode(
            BucketType _bt,
            NodeType _nt,
            std::string _id,
            int _weight,
            Node* _parent
        );
        ~TestNode() {};
        virtual BucketType getBucketType();
        virtual NodeType getNodeType();
        virtual std::string getId();
        virtual int getWeight();
        virtual bool failed();
        virtual bool overloaded();
        virtual bool isLeaf();
        virtual Node* parent();
        virtual std::vector<Node&> children();

        void setFail(bool status);
        void setOverload(bool status);
        void addChild(Node& child);
    private:
        BucketType bt;
        NodeType nt;
        std::string id;
        int weight;
        bool failed_;
        bool overloaded_;
        bool leaf;
        Node* parent_;
        std::vector<Node&> children_;
};

void destroyNodesRecursive(Node& root);
Node& sampleCluster(BucketType bt);
void printNodes(Node& root);

#endif