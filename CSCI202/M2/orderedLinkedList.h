// File: orderedLinkedList.h
#ifndef H_orderedListType
#define H_orderedListType
 
#include "linkedList.h"
 
using namespace std; 
 
// This class keeps the data sorted. 
// Every insertion involves a search to find the correct location.
template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const; 
      // Function to determine whether searchItem is in the list.

    void insert(const Type& newItem);
      // Function to insert newItem in the proper place to maintain order.

    void insertFirst(const Type& newItem);
      // Overridden to call insert() to ensure order is not broken.

    void insertLast(const Type& newItem);
      // Overridden to call insert() to ensure order is not broken.

    void deleteNode(const Type& deleteItem);
      // Function to delete deleteItem from the list.
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; 

    current = this->first; 

    // Because the list is sorted, we can stop early if current->info 
    // becomes greater than the searchItem.
    while (current != nullptr && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;

    if (found)
       found = (current->info == searchItem); // Verify it's an exact match

    return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current;      // pointer to traverse the list
    nodeType<Type> *trailCurrent; // pointer just before current
    nodeType<Type> *newNode;      // pointer to create a node

    bool  found;

    newNode = new nodeType<Type>; 
    newNode->info = newItem;      
    newNode->link = nullptr;      

    if (this->first == nullptr)   // Case 1: List is empty
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;

        // Search for the first element that is NOT less than newItem
        while (current != nullptr && !found) 
            if (current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == this->first)      // Case 2: New item is the smallest
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else                             // Case 3: Insert in middle or at the end
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == nullptr)      // If inserted at the very end
                this->last = newNode;

            this->count++;
        }
    }
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem); // Redirected to maintain sort order
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem); // Redirected to maintain sort order
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;      
    nodeType<Type> *trailCurrent; 
    bool found;

    if (this->first == nullptr) 
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = this->first;
        found = false;

        // Find the node to delete
        while (current != nullptr && !found)  
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == nullptr)   
            cout << "The item to be deleted is not in the list." << endl;
        else
            if (current->info == deleteItem) 
            {
                if (this->first == current) // Delete first node
                {
                    this->first = this->first->link;

                    if (this->first == nullptr)
                        this->last = nullptr;

                    delete current;
                }
                else // Delete middle or last node
                {
                    trailCurrent->link = current->link;

                    if (current == this->last)
                        this->last = trailCurrent;

                    delete current;
                }
                this->count--;
            }
            else // Item is not in the list (we passed its potential spot)
                cout << "The item to be deleted is not in the list." << endl;
    }
}

#endif