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

void destroyNodesRecursive(Node& root) {

}

Node& sampleCluster(BucketType bt) {
    TestNode * root = new TestNode(bt, NodeType::ROOT, "root", 1, nullptr);

    return (Node&) *root;
}

void printNodes(Node& root) {

}

// Helper functions for Implemented Class
void TestNode::setFail(bool status) {
    failed_ = status;
}

void TestNode::setOverload(bool status) {
    overloaded_ = status;
}

void TestNode::addChild(Node& child) {
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

std::vector<Node&> TestNode::children() {
    return children_;
}