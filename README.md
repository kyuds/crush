# crush

[WIP] Implementation of [CRUSH](https://ceph.com/assets/pdfs/weil-crush-sc06.pdf) in C++. 

To use, there are two parts of the code that must be modified. First, in `common.hh`, the enum `NodeType` should be modified so that the relevant types for the relevant cluster is described. Then, the abstract (virtual) class `Node` in `node.hh` should be implemented, along with additional methods to construct the cluster map. An example of such an implementation is described in `test_node.cc`.