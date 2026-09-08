// dynamic_memory_demo1.cpp
// to compile: g++ dynamic_memory_demo1.cpp -o dynamic_memory_demo1.exe
// to run: ./dynamic_memory_demo1.exe
#include <iostream>
using namespace std;

int main()
{
   // --- 1. THE POINTER (STACK MEMORY) ---
   // 'p' is a pointer variable stored on the STACK.
   // Memory allocated: Automatic (Stack). Holds a memory address, currently uninitialized.
   int *p;

   // --- 2. THE NAMED VARIABLE (STACK MEMORY) ---
   // 'x' is a local variable stored on the STACK.
   // Memory allocated: Automatic (Stack). Memory size fixed at compile time.
   int x = 50;

   // 'p' (on the Stack) now holds the memory address of 'x' (also on the Stack).
   p = &x;
   cout << "Value of the named variable x: " << *p << endl;

   // --- 3. DYNAMIC MEMORY ALLOCATION (HEAP MEMORY) ---
   /* The line below allocates memory on the HEAP:
      1. 'new int' allocates dynamic memory on the HEAP for an unnamed integer.
      2. 'p' (which lives on the STACK) is updated to store the address of this HEAP memory location.
      3. Memory lifetime: Persists until explicitly freed with 'delete' (unlike stack variables). */
   p = new int;

   // --- 4. ACCESSING THE DYNAMIC (HEAP) MEMORY ---
   /* We dereference 'p' (stored on Stack) to assign the value 100 directly
      into the dynamically allocated space on the HEAP. */
   *p = 100;

   cout << "Value of the nameless variable: " << *p << endl;
   cout << "Memory address of the nameless variable: " << p << endl;

   // --- 5. CLEANING UP (HEAP MEMORY RELEASE) ---
   /* Releases the dynamically allocated HEAP memory pointed to by 'p'.
      Note: 'p' itself still lives on the STACK until main() returns,
      but the memory it pointed to on the HEAP is now deallocated. */
   delete p;

   return 0;
}