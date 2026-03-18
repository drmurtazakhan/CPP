// myStack.h
 
#ifndef H_StackType 
#define H_StackType
 
#include <iostream> 
#include <cassert>
#include "stackADT.h"
 
using namespace std;

// This class inherits from the stackADT interface.
template <class Type>
class stackType: public stackADT<Type>
{
public:
    // Overload the assignment operator to handle deep copying of stack objects.
    const stackType<Type>& operator=(const stackType<Type>&); 

    // Sets stackTop to 0 to effectively "empty" the stack.
    void initializeStack();

    // Checks if the stack is empty by looking at the stackTop index.
    bool isEmptyStack() const;

    // Checks if stackTop has reached the maximum size of the array.
    bool isFullStack() const;

    // Inserts a new element at the index pointed to by stackTop.
    void push(const Type& newItem);

    // Returns the element at index (stackTop - 1).
    Type top() const;

    // Removes the top element by simply decrementing the stackTop index.
    void pop();

    // Constructor: Dynamically allocates an array of a specific size (default 100).
    stackType(int stackSize = 100); 

    // Copy Constructor: Used when a new stack is created as a copy of an existing one.
    stackType(const stackType<Type>& otherStack); 

    // Destructor: Frees the memory allocated for the array to prevent memory leaks.
    ~stackType(); 

private:
    int maxStackSize; // Maximum number of elements the stack can hold.
    int stackTop;     // Index of the next available slot (also represents count).
    Type *list;       // Pointer to the dynamically allocated array.

    // Helper function used by the assignment operator and copy constructor.
    void copyStack(const stackType<Type>& otherStack); 
};

// --- Member Function Implementations ---

template <class Type>
void stackType<Type>::initializeStack()
{
    // By setting stackTop to 0, we treat the array as empty regardless of old data.
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    // If stackTop is 0, no elements have been pushed.
    return (stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
    // If stackTop equals maxStackSize, the array is out of space.
    return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;   // Store item at current top index.
        stackTop++;                 // Move index to the next empty slot.
    }
    else
        cout << "Cannot add to a full stack." << endl;
}

template <class Type>
Type stackType<Type>::top() const
{
    // Program crashes if top() is called on an empty stack to prevent undefined behavior.
    assert(stackTop != 0);      
    return list[stackTop - 1];  // Top element is always one behind stackTop.
}

template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--;             // Simply move the index back; the slot is now "available."
    else
        cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
stackType<Type>::stackType(int stackSize) 
{
    // Ensure size is positive; otherwise, default to 100.
    if (stackSize <= 0)
    {
        cout << "Size of the array must be positive. Creating array of size 100." << endl;
        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;

    stackTop = 0;                   
    list = new Type[maxStackSize];  // Dynamic memory allocation.
}

template <class Type>
stackType<Type>::~stackType() 
{
    delete [] list; // Important: releases the memory back to the system.
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{ 
    delete [] list;	                 // Clear existing data.
    maxStackSize = otherStack.maxStackSize;	
    stackTop = otherStack.stackTop;	
	  
    list = new Type[maxStackSize];   // Allocate new space.

    // Manually copy every element from the source stack to this one.
    for (int j = 0; j < stackTop; j++)  
        list[j] = otherStack.list[j];
}

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = nullptr;
    copyStack(otherStack);           // Reuse copyStack logic.
}

template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack)
{ 
    if (this != &otherStack)         // Check to ensure we aren't copying the object to itself.
        copyStack(otherStack);

    return *this; 
}         

#endif