// test_hash_string.cpp
// g++ HashTableString.cpp test_hash_string.cpp -o test_hash_string.exe
// .\test_hash_string.exe
#include "HashTableString.h"

int main() {
    initializeHT();

    // These two will collide (same index = 2)
    insert((char*)"Cat");
    insert((char*)"Dog");

    // Collisions for better demonstration
    insert((char*)"abc");   
    insert((char*)"cba");   
    insert((char*)"bca");   

    display();

    return 0;
}