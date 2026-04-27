// test_hash_int.cpp
// g++ HashTableInt.cpp test_hash_int.cpp -o test_hash_int.exe
// .\test_hash_int.exe

#include "HashTableInt.h"

int main() {
    initializeHTInt();

    insertInt(11);
    insertInt(22);
    insertInt(31);
    insertInt(11); // duplicate

    displayInt();

    return 0;
}