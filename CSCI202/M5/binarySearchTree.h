#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include "binaryTree.h"
 
using namespace std;

template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const;
    void insert(const elemType& insertItem);
    void deleteNode(const elemType& deleteItem);

private:
    void deleteFromTree(nodeType<elemType>* &p);
};

template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const {
    nodeType<elemType> *current;
    bool found = false;

    if (this->root == nullptr)
        cout << "Cannot search an empty tree." << endl;
    else {
        current = this->root;
        while (current != nullptr && !found) {
            if (current->info == searchItem) found = true;
            else if (current->info > searchItem) current = current->lLink;
            else current = current->rLink;
        }
    }
    return found;
}

template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem) {
    nodeType<elemType> *current; 
    nodeType<elemType> *trailCurrent = nullptr; 
    nodeType<elemType> *newNode;

    newNode = new nodeType<elemType>;
    newNode->info = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if (this->root == nullptr)
        this->root = newNode;
    else {
        current = this->root;
        while (current != nullptr) {
            trailCurrent = current;
            if (current->info == insertItem) {
                cout << "The item to be inserted is already in the tree -- ";
                cout << "duplicates are not allowed." << endl;
                delete newNode;
                return;
            }
            else if (current->info > insertItem) current = current->lLink;
            else current = current->rLink;
        }
        if (trailCurrent->info > insertItem) trailCurrent->lLink = newNode;
        else trailCurrent->rLink = newNode;
    }
}

template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem) {
    nodeType<elemType> *current; 
    nodeType<elemType> *trailCurrent; 
    bool found = false;

    if (this->root == nullptr)
        cout << "Cannot delete from an empty tree." << endl;
    else {
        current = this->root;
        trailCurrent = this->root;
        while (current != nullptr && !found) {
            if (current->info == deleteItem) found = true;
            else {
                trailCurrent = current;
                if (current->info > deleteItem) current = current->lLink;
                else current = current->rLink;
            }
        }
        if (current == nullptr)
            cout << "The item to be deleted is not in the tree." << endl;
        else if (found) {
            if (current == this->root) deleteFromTree(this->root);
            else if (trailCurrent->info > deleteItem) deleteFromTree(trailCurrent->lLink);
            else deleteFromTree(trailCurrent->rLink);
        }
    }
}

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree(nodeType<elemType>* &p) {
    nodeType<elemType> *current; 
    nodeType<elemType> *trailCurrent; 
    nodeType<elemType> *temp; 

    if (p == nullptr)
        cout << "Error: The node to be deleted does not exist." << endl;
    else if (p->lLink == nullptr && p->rLink == nullptr) {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if (p->lLink == nullptr) {
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if (p->rLink == nullptr) {
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else {
        current = p->lLink;
        trailCurrent = nullptr;
        while (current->rLink != nullptr) {
            trailCurrent = current;
            current = current->rLink;
        }
        p->info = current->info;
        if (trailCurrent == nullptr) p->lLink = current->lLink;
        else trailCurrent->rLink = current->lLink;
        delete current;
    }
}

#endif