// stackADT.h 

#ifndef H_StackADT
#define H_StackADT 
  
// The template <class Type> allows this interface to work with any data type.
template <class Type>
class stackADT
{
public:
    // Pure virtual function to reset the stack to an empty state.
    virtual void initializeStack() = 0;
     
    // Returns true if no elements are in the stack, false otherwise.
    virtual bool isEmptyStack() const = 0;

    // Returns true if the stack has reached its maximum allocated capacity.
    virtual bool isFullStack() const = 0;

    // Adds a new item to the very top of the stack.
    virtual void push(const Type& newItem) = 0;

    // Returns the current top element without removing it.
    virtual Type top() const = 0;

    // Removes the top element from the stack.
    virtual void pop() = 0;
};
        
#endif