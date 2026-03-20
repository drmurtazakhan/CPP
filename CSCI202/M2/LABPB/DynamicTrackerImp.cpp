// DynamicTrackerImp.cpp
#include <iostream>
#include "DynamicTracker.h"
using namespace std;

// Allocates memory for one integer on the heap [cite: 21]
void DynamicTracker::initialize() {
    ptr = new int; 
    *ptr = 0; // Set starting value to 0
}

// Assigns value only if memory is allocated [cite: 9]
void DynamicTracker::setValue(int v) {
    if (ptr != nullptr) {
        *ptr = v;
    }
}

// Returns value or -1 if pointer is null [cite: 10]
int DynamicTracker::getValue() const {
    if (ptr == nullptr) {
        return -1;
    }
    return *ptr;
}

// Returns the actual memory address [cite: 7]
int* DynamicTracker::getAddress() const {
    return ptr;
}

// Frees the heap memory and prevents dangling pointers [cite: 11]
void DynamicTracker::cleanup() {
    delete ptr;
    ptr = nullptr;
}