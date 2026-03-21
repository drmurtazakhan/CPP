/* * File: linkedList.h 
 */
#ifndef H_LinkedListType
#define H_LinkedListType
   
#include <iostream>
#include <cassert>
 
using namespace std;

// Definition of the node: The basic building block of the linked list.
// Each node contains the data (info) and a pointer to the next node (link).
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

// linkedListIterator: Allows for the traversal of the list similar to pointer arithmetic
// but specifically designed for non-contiguous memory structures.
template <class Type>
class linkedListIterator
{
public:
   linkedListIterator();
   linkedListIterator(nodeType<Type> *ptr);

   Type operator*();
     // Returns the data stored in the current node.

   linkedListIterator<Type> operator++();    
     // Advances the iterator to the next node in the list.

   bool operator==(const linkedListIterator<Type>& right) const; 
   bool operator!=(const linkedListIterator<Type>& right) const; 

private:
   nodeType<Type> *current; // Internal pointer to the node the iterator is currently on.
};

// --- linkedListIterator Implementation ---

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()   
{
    current = current->link; // Move to the next memory address stored in the link field.
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{    
    return (current != right.current);
}


// ***************** class linkedListType   ****************
// This is an abstract class. Functions like search, insertFirst, and deleteNode
// are virtual because their logic changes depending on if the list is ordered or unordered.

template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);  

    void initializeList(); 
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList();
    Type front() const; 
    Type back() const; 

    // Abstract methods to be implemented by derived classes (Unordered vs Ordered).
    virtual bool search(const Type& searchItem) const = 0;
    virtual void insertFirst(const Type& newItem) = 0;
    virtual void insertLast(const Type& newItem) = 0;
    virtual void deleteNode(const Type& deleteItem) = 0;

    linkedListIterator<Type> begin();
      // Returns an iterator pointing to the first node.

    linkedListIterator<Type> end();
      // Returns an iterator pointing to nullptr (past the last node).

    linkedListType(); 
    linkedListType(const linkedListType<Type>& otherList); 
    ~linkedListType();   

protected:
    int count;             // Tracks the current number of nodes.
    nodeType<Type> *first; // Pointer to the very first node (Head).
    nodeType<Type> *last;  // Pointer to the very last node (Tail).

private: 
    void copyList(const linkedListType<Type>& otherList); 
      // Helper function used by copy constructor and assignment operator.
};

// --- linkedListType Implementation ---

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == nullptr);
}

template <class Type>
linkedListType<Type>::linkedListType()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;   
    while (first != nullptr)   
    {                          
        temp = first;        // Save current node
        first = first->link; // Advance head to next node
        delete temp;         // Deallocate memory to prevent memory leaks
    }
    last = nullptr;
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); 
}

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current = first; 
    while (current != nullptr) 
    {
        cout << current->info << " ";
        current = current->link;
    }
}

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{   
    assert(first != nullptr); // Ensure the list isn't empty before accessing data.
    return first->info; 
}

template <class Type>
Type linkedListType<Type>::back() const
{   
    assert(last != nullptr);
    return last->info; 
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(nullptr);
    return temp;
}

// copyList: Performs a 'deep copy'. Instead of just copying pointers,
// it creates entirely new nodes in memory and copies the data over.
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList) 
{
    nodeType<Type> *newNode; 
    nodeType<Type> *current; 

    if (first != nullptr) 
       destroyList();

    if (otherList.first == nullptr) 
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.first; 
        count = otherList.count;

        // Step 1: Copy the head node
        first = new nodeType<Type>;  
        first->info = current->info; 
        first->link = nullptr;        
        last = first;              
        current = current->link;     

        // Step 2: Traverse the source list and create new nodes for the destination list
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;  
            newNode->info = current->info; 
            newNode->link = nullptr;       
            last->link = newNode;  // Link the previous node to this new node
            last = newNode;        // Move 'last' pointer to the new end of the list
            current = current->link;   
        }
    }
}

template <class Type>
linkedListType<Type>::~linkedListType() 
{
   destroyList(); // Automatically cleans up memory when the object goes out of scope.
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
    first = nullptr;
    copyList(otherList);
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{ 
    if (this != &otherList) // Critical: prevent deleting the list if assigned to itself.
    {
        copyList(otherList);
    }
     return *this; 
}

#endif