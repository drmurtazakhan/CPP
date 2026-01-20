#include <iostream>
using namespace std;

int main() {
    // --- 1. THE POINTER (The "Address Book") ---
    // p is a pointer. It doesn't hold a number like 100; 
    // it holds the location of where a number is kept.
    int *p; 

    // --- 2. THE NAMED VARIABLE (The "House with a Name") ---
    // x is a standard variable. It has a name 'x' and a specific spot in memory.
    int x = 50; 

    // p now stores the address of x. 
    // p is "pointing" to a variable that already has a name.
    p = &x;
    cout << "Value of the named variable x: " << *p << endl;

    // --- 3. THE NAMELESS VARIABLE (Dynamic Memory) ---
    /* The line below does something special:
       1. It carves out a brand new space for an int in the "Heap" memory.
       2. This new space has NO NAME. You cannot type 'cout << nameless;' 
       3. It returns the address of that nameless spot and saves it in 'p'. */
    p = new int; 

    // --- 4. ACCESSING THE NAMELESS VARIABLE ---
    /* Since the variable has no name, we MUST use the asterisk (*) 
       to 'dereference' the pointer. This is like using a GPS to 
       find a house that doesn't have a mailbox name. */
    *p = 100; // We are putting 100 into that nameless memory spot.

    cout << "Value of the nameless variable: " << *p << endl;
    cout << "Memory address of the nameless variable: " << p << endl;

    // --- 5. CLEANING UP ---
    /* Because the variable is nameless and created with 'new', 
       the computer won't automatically delete it when the program ends. 
       We must manually 'delete' it to free up that memory. */
    delete p; 

    return 0;
}