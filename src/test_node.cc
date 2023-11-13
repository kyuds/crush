#include "test_node.hh"

#include <iostream>

// constructor
// I know, its messy...
TestNode::TestNode(BucketType _bt, NodeType _nt, std::string _id, int _weight, Node* _parent) {
    bt = _bt;
    nt = _nt;
    id = _id;
    weight = _weight;
    parent_ = _parent;

    failed_ = false;
    overloaded_ = false;
    leaf = true;
}

Node* sampleCluster(BucketType bt) {
    TestNode * root = new TestNode(bt, NodeType::ROOT, "root", 1, nullptr);

    std::vector<TestNode*> store1;
    for (int i = 0; i < 3; i++) {
        auto name = "r0" + std::to_string(i);
        auto nd = new TestNode(bt, NodeType::ROW, name, 1, root);
        root->addChild(nd);
        store1.push_back(nd);
    }

    std::vector<TestNode*> store2;
    int id = 0;
    for (auto p : store1) {
        for (int i = 0; i < 3; i++) {
            auto name = "c0" + std::to_string(id++);
            auto nd = new TestNode(bt, NodeType::CABINET, name, 1, p);
            p->addChild(nd);
            store2.push_back(nd);
        }
    }

    id = 0;
    for (auto p : store2) {
        for (int i = 0; i < 3; i++) {
            std::string name;
            if (id < 10) {
                name = "d0" + std::to_string(id++);
            } else {
                name = "d" + std::to_string(id++);
            }
            auto nd = new TestNode(bt, NodeType::DISK, name, 1, p);
            p->addChild(nd);
        }
    }

    return (Node*) root;
}

void printNodes(Node* root, int offset) {
    std::cout << std::string(offset, ' ') + "- " + root->getId() << std::endl;
    for (auto n : root->children()) {
        printNodes(n, offset + 3);
    }
}

void destroyNodesRecursive(Node* root) {
    if (!root->isLeaf()) {
        for (auto n : root->children()) {
            destroyNodesRecursive(n);
        }
    }
    delete root;
}

// Helper functions for Implemented Class
void TestNode::setFail(bool status) {
    failed_ = status;
}

void TestNode::setOverload(bool status) {
    overloaded_ = status;
}

void TestNode::addChild(Node* child) {
    leaf = false;
    children_.push_back(child);
}

// Implementation of Abstract Class
BucketType TestNode::getBucketType() {
    return bt;
}

NodeType TestNode::getNodeType() {
    return nt;
}

std::string TestNode::getId() {
    return id;
}

int TestNode::getWeight() {
    return weight;
}

bool TestNode::failed() {
    return failed_;
}

bool TestNode::overloaded() {
    return overloaded_;
}

bool TestNode::isLeaf() {
    return leaf;
}

Node* TestNode::parent() {
    return parent_;
}

std::vector<Node*> TestNode::children() {
    return children_;
}