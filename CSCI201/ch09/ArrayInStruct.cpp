// ArrayInStruct.cpp
// Compile: g++  ArrayInStruct.cpp -o ArrayInStruct.exe
// Run:     ./ArrayInStruct.exe

// This program demonstrates how to use a struct that contains an array to store a list of integers
#include <iostream>
using namespace std;

// Define the maximum size of the array
const int ARRAY_SIZE = 1000;

// Define the struct that holds both the array and its current length
struct listType
{
    int listElem[ARRAY_SIZE]; // Array containing the list elements
    int listLength;           // Keeps track of how many items are actually in the list
};

// Function Prototype for the sequential search
// Passed by constant reference (const &) to save memory and prevent modifications
int seqSearch(const listType &list, int searchItem);

int main()
{
    // Declare a struct variable of type listType
    listType intList;

    // Initialize the list using the steps from the image
    intList.listLength = 0;   // Line 1: Start with an empty list
    intList.listElem[0] = 12; // Line 2: Add 12 to the first position
    intList.listLength++;     // Line 3: Increase length to 1
    intList.listElem[1] = 37; // Line 4: Add 37 to the second position
    intList.listLength++;     // Line 5: Increase length to 2

    // Item we want to find in the list
    int itemToFind = 37;

    // Call the search function
    int resultIndex = seqSearch(intList, itemToFind);

    // Print the results
    if (resultIndex != -1)
    {
        cout << "Item " << itemToFind << " found at index: " << resultIndex << endl;
    }
    else
    {
        cout << "Item " << itemToFind << " was not found in the list." << endl;
    }

    return 0;
}

// Function Implementation: Sequential Search
int seqSearch(const listType &list, int searchItem)
{
    int loc;
    bool found = false;

    // Loop through the array only up to the current listLength
    for (loc = 0; loc < list.listLength; loc++)
    {
        if (list.listElem[loc] == searchItem)
        {
            found = true;
            break; // Stop looking once the item is found
        }
    }

    // Return the index location if found, otherwise return -1
    if (found)
        return loc;
    else
        return -1;
}