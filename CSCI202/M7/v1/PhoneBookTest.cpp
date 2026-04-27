// PhoneBookTest.cpp
// g++ PhoneBookTest.cpp -o PhoneBookTest.exe
// ./PhoneBookTest.exe

#include <iostream>
#include <string>
#include "ChainedHashMap.h"

int main() {
    // Create a HashMap for a phone book
    ChainedHashMap<std::string, std::string> phoneBook(10);

    std::cout << "--- Initializing Phone Book ---" << std::endl;

    // Adding entries using the 'put' function logic
    phoneBook.put("Alice", "555-0123");
    phoneBook.put("Bob", "555-4567");
    phoneBook.put("Charlie", "555-8910");

    std::cout << "Added Alice, Bob, and Charlie." << std::endl;
    std::cout << "Current Map Size: " << phoneBook.size() << std::endl;

    // Testing the replacement logic (Updating Alice's number)
    std::cout << "\nUpdating Alice's number..." << std::endl;
    phoneBook.put("Alice", "555-9999");

    // Retrieving data
    try {
        std::cout << "Alice's New Number: " << phoneBook.get("Alice") << std::endl;
        std::cout << "Bob's Number:       " << phoneBook.get("Bob") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nTest Complete. Map Size remains: " << phoneBook.size() << std::endl;

    return 0;
}