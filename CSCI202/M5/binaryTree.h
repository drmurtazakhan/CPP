#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>

using namespace std;

// Definition of the Node
template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};

// Definition of the Abstract Base Class
template <class elemType>
class binaryTreeType
{
public:
    // Overload the assignment operator
    const binaryTreeType<elemType> &operator=(const binaryTreeType<elemType> &);

    // Check if the tree is empty
    bool isEmpty() const;

    // --- Standard Traversal Functions ---
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;

    // --- Traversal Functions with Function Parameters ---
    void inorderTraversal(void (*visit)(elemType &));
    void preorderTraversal(void (*visit)(elemType &));
    void postorderTraversal(void (*visit)(elemType &));

    // --- Tree Information Functions ---
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    void destroyTree();

    // --- Abstract Functions ---
    virtual bool search(const elemType &searchItem) const = 0;
    virtual void insert(const elemType &insertItem) = 0;
    virtual void deleteNode(const elemType &deleteItem) = 0;

    // Constructors and Destructor
    binaryTreeType();
    binaryTreeType(const binaryTreeType<elemType> &otherTree);
    virtual ~binaryTreeType();

protected:
    nodeType<elemType> *root;

private:
    // Helper logic for deep copying
    void copyTree(nodeType<elemType> *&copiedTreeRoot, nodeType<elemType> *otherTreeRoot);
    void destroy(nodeType<elemType> *&p);

    // Internal Recursive Traversals (Standard)
    void inorder(nodeType<elemType> *p) const;
    void preorder(nodeType<elemType> *p) const;
    void postorder(nodeType<elemType> *p) const;

    // Internal Recursive Traversals (Using Function Pointers)
    void inorder(nodeType<elemType> *p, void (*visit)(elemType &));
    void preorder(nodeType<elemType> *p, void (*visit)(elemType &));
    void postorder(nodeType<elemType> *p, void (*visit)(elemType &));

    // Internal Recursive Tree Metrics
    int height(nodeType<elemType> *p) const;
    int max(int x, int y) const;
    int nodeCount(nodeType<elemType> *p) const;
    int leavesCount(nodeType<elemType> *p) const;
};

// --- IMPLEMENTATION ---

// Default Constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = nullptr;
}

// Copy Constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType> &otherTree)
{
    if (otherTree.root == nullptr)
    {
        root = nullptr;
    }
    else
    {
        copyTree(root, otherTree.root);
    }
}

// Overloaded Assignment Operator
template <class elemType>
const binaryTreeType<elemType> &binaryTreeType<elemType>::operator=(const binaryTreeType<elemType> &otherTree)
{
    if (this != &otherTree)
    {
        if (root != nullptr)
        {
            destroy(root);
        }
        if (otherTree.root == nullptr)
        {
            root = nullptr;
        }
        else
        {
            copyTree(root, otherTree.root);
        }
    }
    return *this;
}

// Helper function to perform deep copy
template <class elemType>
void binaryTreeType<elemType>::copyTree(nodeType<elemType> *&copiedTreeRoot, nodeType<elemType> *otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
    {
        copiedTreeRoot = nullptr;
    }
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == nullptr);
}

// Public Traversal Starters
template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const { inorder(root); }

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const { preorder(root); }

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const { postorder(root); }

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal(void (*visit)(elemType &)) { inorder(root, visit); }

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal(void (*visit)(elemType &)) { preorder(root, visit); }

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal(void (*visit)(elemType &)) { postorder(root, visit); }

// Recursive implementations with Function Pointers
template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p, void (*visit)(elemType &))
{
    if (p != nullptr)
    {
        inorder(p->lLink, visit);
        (*visit)(p->info);
        inorder(p->rLink, visit);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p, void (*visit)(elemType &))
{
    if (p != nullptr)
    {
        (*visit)(p->info);
        preorder(p->lLink, visit);
        preorder(p->rLink, visit);
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p, void (*visit)(elemType &))
{
    if (p != nullptr)
    {
        postorder(p->lLink, visit);
        postorder(p->rLink, visit);
        (*visit)(p->info);
    }
}

// Recursive Counting Logic
template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const { return nodeCount(root); }

template <class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p) const
{
    if (p == nullptr)
    {
        return 0;
    }
    return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const { return leavesCount(root); }

template <class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p) const
{
    if (p == nullptr)
    {
        return 0;
    }
    if (p->lLink == nullptr && p->rLink == nullptr)
    {
        return 1;
    }
    return leavesCount(p->lLink) + leavesCount(p->rLink);
}

// Standard Print Traversals
template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

// Destructor and Memory Management
template <class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType> *&p)
{
    if (p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

// Height logic
template <class elemType>
int binaryTreeType<elemType>::treeHeight() const { return height(root); }

template <class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p) const
{
    if (p == nullptr)
        return 0;
    return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const { return (x >= y) ? x : y; }

#endif