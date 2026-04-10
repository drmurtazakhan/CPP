// test_flexible_traversal.cpp
// compile with: g++ test_flexible_traversal.cpp -o test_flexible_traversal.exe
// execute with: ./test_flexible_traversal.exe
#include <iostream>
#include "binaryTree.h"

using namespace std;

// This class allows us to instantiate an object of the abstract binaryTreeType
template <class elemType>
class concreteTree : public binaryTreeType<elemType> {
public:
    // Required dummy implementations for abstract functions
    bool search(const elemType& item) const { return false; }
    void insert(const elemType& item) { }
    void deleteNode(const elemType& item) { }

    // Manually link nodes to create a test tree
    void buildManualTree() {
        // Create root: 10
        this->root = new nodeType<elemType>{10, nullptr, nullptr};
        
        // Left child: 20
        this->root->lLink = new nodeType<elemType>{20, nullptr, nullptr};
        
        // Right child: 30
        this->root->rLink = new nodeType<elemType>{30, nullptr, nullptr};
    }
};

// --- Custom "Visit" Functions ---

// 1. A function to simply print the value
void printItem(int& x) {
    cout << "[" << x << "] ";
}

// 2. A function to double the value (modifies the actual tree data)
void doubleItem(int& x) {
    x = x * 2;
}

// 3. A function to square the value
void squareItem(int& x) {
    x = x * x;
}

int main() {
    concreteTree<int> myTree;
    myTree.buildManualTree();

    cout << "Initial Tree (Inorder): " << endl;
    myTree.inorderTraversal(printItem); // Passing printItem as a parameter
    cout << endl << "---------------------------" << endl;

    // Task 1: Double all values using Inorder traversal
    cout << "Doubling all nodes..." << endl;
    myTree.inorderTraversal(doubleItem);
    
    cout << "Updated Tree: ";
    myTree.inorderTraversal(printItem);
    cout << endl << "---------------------------" << endl;

    // Task 2: Square all values using Preorder traversal
    cout << "Squaring all nodes..." << endl;
    myTree.preorderTraversal(squareItem);
    
    cout << "Updated Tree: ";
    myTree.inorderTraversal(printItem);
    cout << endl;

    return 0;
}