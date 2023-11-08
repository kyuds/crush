#include "crush.hh"

#include <stdexcept>

#include "selector.hh"

// select algorithm from figure <Algorithm 1>
std::vector<Node> select(Node &root, long input, int count, NodeType t, bool first_n) {
    std::vector<Node> selected;

    int total_failure = 0;

    for (int r = 0; r < count; r++) {
        int failure = 0;
        bool retry_descent, retry_bucket;
        Node* fnd = nullptr;

        do {
            retry_descent = false;
            Node& bucket = root;

            do {
                retry_bucket = false;
                int round;
                if (first_n) {
                    round = r + total_failure;
                } else {
                    round = r + count * failure;
                }

                Node& candidate = select(bucket, input, round);

                if (candidate.getNodeType() == t) {
                    bool contains = containNode(candidate, selected);

                    if (contains || candidate.failed() || candidate.overloaded()) {
                        failure++;
                        total_failure++;

                        if (contains && failure < 3) {
                            retry_bucket = true;
                        } else {
                            retry_descent = true;
                        }
                    } else {
                        fnd = &candidate;
                    }
                } else {
                    if (bucket.isLeaf()) {
                        throw std::invalid_argument("Bucket is leaf, thus cannot traverse further down.");
                    }
                    bucket = candidate;
                    retry_bucket = true;
                }
            } while (retry_bucket);
        } while (retry_descent);

        if (fnd == nullptr) {
            throw std::invalid_argument("Got nullptr for found candidate.");
        }
        selected.push_back(*fnd);
    }
    
    return selected;
}

// helpers
bool containNode(Node& candidate, std::vector<Node> selected) {
    for (auto n : selected) {
        if (candidate.getId() == n.getId()) {
            return false;
        }
    }
    return true;
}