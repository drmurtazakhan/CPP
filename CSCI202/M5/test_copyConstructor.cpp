// test_copyConstructor.cpp
// compile: g++ test_copyConstructor.cpp -o test_copyConstructor.exe
// execute: ./test_copyConstructor.exe
#include <iostream>
#include "binaryTree.h"

using namespace std;

template <class elemType>
class temporaryTree : public binaryTreeType<elemType>
{
public:
    // Dummy implementations for abstract functions
    bool search(const elemType &item) const { return false; }
    void insert(const elemType &item) {}
    void deleteNode(const elemType &item) {}

    void buildManualTree()
    {
        this->root = new nodeType<elemType>{10, nullptr, nullptr};
        this->root->lLink = new nodeType<elemType>{20, nullptr, nullptr};
        this->root->rLink = new nodeType<elemType>{30, nullptr, nullptr};
    }
};

int main()
{
    temporaryTree<int> tree1;
    tree1.buildManualTree();

    // copy constructor test
    temporaryTree<int> tree2(tree1);

    cout << "\nPreorder Traversal (Root-L-R) of tree1:  ";
    tree1.preorderTraversal();

    cout << "\nPreorder Traversal (Root-L-R) of tree2:  ";
    tree2.preorderTraversal();

    return 0;
}