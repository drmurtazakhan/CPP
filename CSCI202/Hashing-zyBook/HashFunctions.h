// HashFunctions.h
// Section 6.1: Hash codes and hash functions.
//
// A hash code is a fixed-size, NON-NEGATIVE integer that attempts to uniquely
// identify a key. A hash function computes a hash code for a given value.
// Hash functions are commonly specific to a data type.
#pragma once
#include <string>

// Hash function for strings: sums all character codes.
// This is one of the simplest approaches, but different strings can share a
// hash code (Ex: "TAB" and "BAT" both give 215).
inline int HashString(const std::string& value) {
   int hashCode = 0;
   for (int character : value) {
      hashCode += character;   // add each character's code
   }
   // Setting the sign bit (highest bit) to 0 guarantees a non-negative result.
   return (int)(hashCode & 0x7fffffff);
}

// Hash function for ints: returns the same integer with the sign bit set to 0.
// Ex: HashInt(-76) returns 2147483572, HashInt(-2147483648) returns 0.
inline int HashInt(int value) {
   return (int)(value & 0x7fffffff);
}

// A user-defined class: an employee record. Records commonly have a unique ID.
class Employee {
public:
   std::string name;
   int uniqueID;
};

// Hash function for Employee: simply returns the unique employee ID.
// To be a valid hash function, each employee must have a unique ID.
inline int HashEmployee(const Employee& employee) {
   return employee.uniqueID;
}
