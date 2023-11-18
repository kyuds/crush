#include "crush.hh"

#include <stdexcept>

#include "selector.hh"

// helpers
bool containNode(Node * candidate, std::vector<Node*> selected);
Node* select(Node * origin, long input, int round);

// select algorithm from figure <Algorithm 1>
std::vector<Node*> select(Node * root, long input, int count, NodeType t, bool first_n) {
    std::vector<Node*> selected;

    int total_failure = 0;

    for (int r = 0; r < count; r++) {
        int failure = 0;
        bool retry_descent, retry_bucket;
        Node * candidate = nullptr;

        do {
            retry_descent = false;
            Node * bucket = root;

            do {
                retry_bucket = false;
                int round;
                if (first_n) {
                    round = r + total_failure;
                } else {
                    round = r + count * failure;
                }

                candidate = select(bucket, input, round);

                if (candidate->getNodeType() == t) {
                    bool contains = containNode(candidate, selected);

                    if (contains || candidate->failed() || candidate->overloaded()) {
                        failure++;
                        total_failure++;

                        if (contains && failure < 3) {
                            retry_bucket = true;
                        } else {
                            retry_descent = true;
                        }
                    }
                } else {
                    if (bucket->isLeaf()) {
                        throw std::invalid_argument("Bucket is leaf, thus cannot traverse further down.");
                    }
                    bucket = candidate;
                    retry_bucket = true;
                }
            } while (retry_bucket);
        } while (retry_descent);

        if (candidate == nullptr) {
            throw std::invalid_argument("Got nullptr for found candidate.");
        }
        selected.push_back(candidate);
    }
    
    return selected;
}

Node* select(Node * origin, long input, int round) {
    switch(origin->getBucketType()) {
        case UNIFORM:
            return select_uniform(origin, input, round);
        case LIST: 
            return select_list(origin, input, round);
        case TREE:
            return select_tree(origin, input, round);
        case STRAW:
            return select_straw(origin, input, round);
        default:
            throw std::invalid_argument("BucketType doesn't match any defined value.");
    }
}

// helpers
bool containNode(Node * candidate, std::vector<Node*> selected) {
    for (auto n : selected) {
        if (candidate->getId() == n->getId()) {
            return false;
        }
    }
    return true;
}