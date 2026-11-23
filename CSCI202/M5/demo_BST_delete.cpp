// demo_BST_delete.cpp
// Compile with: g++ demo_BST_delete.cpp -o demo_BST_delete.exe
// Execute with: ./demo_BST_delete.exe

#include <iostream>
#include "binarySearchTree.h"

using namespace std;

// Subclass of bSearchTreeType so we can build a specific BST structure manually
template <class elemType>
class demoBST : public bSearchTreeType<elemType> {
public:
    // Builds a BST where all four delete cases can be demonstrated:
    //
    //          50
    //         /  \
    //       30    70
    //      /  \     \
    //    20    40    80
    //   /
    // 10
    //
    // - Leaf (Case 1):                40 (no left or right child)
    // - No left subtree (Case 2):     70 (no left child, has right child 80)
    // - No right subtree (Case 3):    20 (has left child 10, no right child)
    // - Both subtrees (Case 4):       30 (has left child 20 and right child 40)
    void buildManualTree() {
        // Make sure any existing tree is freed first to avoid memory leaks
        this->destroyTree();

        // Create nodes
        auto* n50 = new nodeType<elemType>{50, nullptr, nullptr};
        auto* n30 = new nodeType<elemType>{30, nullptr, nullptr};
        auto* n70 = new nodeType<elemType>{70, nullptr, nullptr};
        auto* n20 = new nodeType<elemType>{20, nullptr, nullptr};
        auto* n40 = new nodeType<elemType>{40, nullptr, nullptr};
        auto* n80 = new nodeType<elemType>{80, nullptr, nullptr};
        auto* n10 = new nodeType<elemType>{10, nullptr, nullptr};

        // Wire up BST links (left < parent < right)
        this->root = n50;

        n50->lLink = n30;
        n50->rLink = n70;

        n30->lLink = n20;
        n30->rLink = n40;

        n20->lLink = n10;
        n70->rLink = n80;
    }
};

// Helper function to print the tree in sorted (inorder) order
void printTree(const demoBST<int>& tree, const string& label) {
    cout << label << " (Inorder): ";
    tree.inorderTraversal();
    cout << endl;
}

int main() {
    demoBST<int> tree;

    // --- CASE 1: Delete a leaf node (40) ---
    tree.buildManualTree();
    cout << "=== Case 1: Delete Leaf Node (40) ===" << endl;
    printTree(tree, "Before");
    tree.deleteNode(40);
    printTree(tree, "After ");
    cout << endl;

    // --- CASE 2: Delete a node with no left subtree (70) ---
    tree.buildManualTree();
    cout << "=== Case 2: Delete Node with No Left Subtree (70) ===" << endl;
    printTree(tree, "Before");
    tree.deleteNode(70);
    printTree(tree, "After ");
    cout << endl;

    // --- CASE 3: Delete a node with no right subtree (20) ---
    tree.buildManualTree();
    cout << "=== Case 3: Delete Node with No Right Subtree (20) ===" << endl;
    printTree(tree, "Before");
    tree.deleteNode(20);
    printTree(tree, "After ");
    cout << endl;

    // --- CASE 4: Delete a node with both left and right subtrees (30) ---
    tree.buildManualTree();
    cout << "=== Case 4: Delete Node with Left and Right Subtrees (30) ===" << endl;
    printTree(tree, "Before");
    tree.deleteNode(30);
    printTree(tree, "After ");
    cout << endl;

    // Destructor automatically cleans up the final tree when main() exits
    return 0;
}