// compile: g++ test_queueAsArray_string.cpp -o test_queueAsArray_string.exe
// run: ./test_queueAsArray_string.exe

#include <iostream>
#include <string>
#include "queueAsArray.h" // Includes the circular array queue implementation[cite: 7]

using namespace std;

int main()
{
    // Create a queue that can hold up to 5 strings
    queueType<string> queue(5);

    cout << "--- Array-Based Queue Demonstration ---" << endl;

    // 1. Add strings to the queue (FIFO: First-In, First-Out)
    cout << "Adding to queue: Ivy, Tech, Community, College" << endl;
    queue.addQueue("Ivy"); // Enters first
    queue.addQueue("Tech");
    queue.addQueue("Community");
    queue.addQueue("College"); // Enters last

    // 2. Inspect the front and back elements
    // front() returns the first item added; back() returns the most recent.
    cout << "Front of the queue: " << queue.front() << endl; // Should be "Ivy"[cite: 7]
    cout << "Back of the queue: " << queue.back() << endl;   // Should be "College"[cite: 7]

    // 3. Remove an element from the front
    cout << "\nRemoving (dequeue) the front element..." << endl;
    queue.deleteQueue(); // Removes "Ivy"[cite: 7]

    // 4. Check the new front element
    cout << "New front of the queue: " << queue.front() << endl; // Should now be "Tech"[cite: 7]

    return 0;
}