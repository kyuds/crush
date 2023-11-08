#include "crush/crush.hh"
#include "crush/types.hh"
#include "test_node.hh"

int main() {
    // create sample cluster
    auto cluster = sampleCluster(BucketType::UNIFORM);
    printNodes(cluster);

    // test crush here.

    // free cluster tree
    destroyNodesRecursive(cluster);

    return 0;
}