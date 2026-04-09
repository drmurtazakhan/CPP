// test_BT_3nodes.cpp
// compile with: g++ test_BT_3nodes.cpp -o test_BT_3nodes.exe
// execute with: ./test_BT_3nodes.exe
#include <iostream>
#include "binaryTree.h"

using namespace std;

// We inherit from binaryTreeType so we can manually access the 'protected' root pointer
template <class elemType>
class temporaryTree : public binaryTreeType<elemType> {
public:
    void buildSimpleTree() {
        // 1. Create the Root node (Value: 10)
        this->root = new nodeType<elemType>;
        this->root->info = 10;

        // 2. Create Left Child (Value: 20)
        this->root->lLink = new nodeType<elemType>;
        this->root->lLink->info = 20;
        this->root->lLink->lLink = nullptr;
        this->root->lLink->rLink = nullptr;

        // 3. Create Right Child (Value: 30)
        this->root->rLink = new nodeType<elemType>;
        this->root->rLink->info = 30;
        this->root->rLink->lLink = nullptr;
        this->root->rLink->rLink = nullptr;
        
        // Structure created:
        //      10
        //     /  \
        //    20  30
    }
};

int main() {
    temporaryTree<int> myTree;

    cout << "Building a simple hardcoded tree..." << endl;
    myTree.buildSimpleTree();

    // Testing Inorder: Left -> Root -> Right
    cout << "\nInorder Traversal (Expected: 20 10 30):" << endl;
    myTree.inorderTraversal();
    cout << endl;

    // Testing Preorder: Root -> Left -> Right
    cout << "\nPreorder Traversal (Expected: 10 20 30):" << endl;
    myTree.preorderTraversal();
    cout << endl;

    // Testing Postorder: Left -> Right -> Root
    cout << "\nPostorder Traversal (Expected: 20 30 10):" << endl;
    myTree.postorderTraversal();
    cout << endl;

    return 0;
}