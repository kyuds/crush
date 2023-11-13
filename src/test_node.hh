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

        BucketType getBucketType() override;
        NodeType getNodeType() override;
        std::string getId() override;
        int getWeight() override;
        bool failed() override;
        bool overloaded() override;
        bool isLeaf() override;
        Node* parent() override;
        std::vector<Node*> children() override;

        void setFail(bool status);
        void setOverload(bool status);
        void addChild(Node* child);
    private:
        BucketType bt;
        NodeType nt;
        std::string id;
        int weight;
        bool failed_;
        bool overloaded_;
        bool leaf;
        Node* parent_;
        std::vector<Node*> children_;
};

Node* sampleCluster(BucketType bt);
void printNodes(Node* root, int offset);
void destroyNodesRecursive(Node* root);

#endif