// LimitedArrayMap.h
// Section 6.1: A limited map ADT implementation.
//
// If all keys are integers in the range [0, 9], a 10-element array can store
// every possible key. The key itself is used as the array index, so insert,
// contains, and remove each run in O(1) time.
//
// Limitations: only works when keys are in [0, 9], and a 2-billion-element
// array (to support every int) is not practical. Hashing solves this.
#pragma once
#include <string>

class LimitedArrayMap {
private:
   static const int SIZE = 10;
   std::string values[SIZE];   // value stored at index = key
   bool occupied[SIZE];        // true if the element holds an item

public:
   LimitedArrayMap() {
      for (int i = 0; i < SIZE; i++) occupied[i] = false;   // all empty
   }

   // Inserts (key, value). An existing item with the same key is replaced.
   // Returns false if the key is outside [0, 9].
   bool Insert(int key, const std::string& value) {
      if (key < 0 || key >= SIZE) return false;
      values[key] = value;
      occupied[key] = true;
      return true;
   }

   // True if the key is in the map.
   bool Contains(int key) const {
      return key >= 0 && key < SIZE && occupied[key];
   }

   // Removes the key; returns true if it existed.
   bool Remove(int key) {
      if (!Contains(key)) return false;
      occupied[key] = false;
      return true;
   }

   // Returns the value for key (empty string if not present).
   std::string Get(int key) const {
      return Contains(key) ? values[key] : "";
   }
};
