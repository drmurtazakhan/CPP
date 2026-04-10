// test_BT_3nodes.cpp
// compile with: g++ test_BT_3nodes.cpp -o test_BT_3nodes.exe
// execute with: ./test_BT_3nodes.exe
#include <iostream>
#include "binaryTree.h"

using namespace std;

template <class elemType>
class temporaryTree : public binaryTreeType<elemType> {
public:
    // Dummy implementations for abstract functions
    bool search(const elemType& item) const { return false; }
    void insert(const elemType& item) { }
    void deleteNode(const elemType& item) { }

    void buildManualTree() {
        this->root = new nodeType<elemType>{10, nullptr, nullptr};
        this->root->lLink = new nodeType<elemType>{20, nullptr, nullptr};
        this->root->rLink = new nodeType<elemType>{30, nullptr, nullptr};
    }
};

int main() {
    temporaryTree<int> myTree;
    myTree.buildManualTree();

    cout << "Nodes: " << myTree.treeNodeCount() << endl;
    cout << "Leaves: " << myTree.treeLeavesCount() << endl;

    cout << "\nInorder Traversal (L-Root-R):   ";
    myTree.inorderTraversal();
    
    cout << "\nPreorder Traversal (Root-L-R):  ";
    myTree.preorderTraversal();
    
    cout << "\nPostorder Traversal (L-R-Root): ";
    myTree.postorderTraversal();
    cout << endl;

    return 0;
}