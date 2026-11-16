// HashTable.h
// Abstract base class for every hash table in this project (Sections 6.1-6.6).
//
// A hash table stores unordered items by mapping (hashing) each key to a
// bucket in an array. A hash map is a map ADT built on a hash table.
//
// Bucket index logic:
//    1. hashCode    = Hash(key)
//    2. bucketIndex = hashCode % numberOfBuckets
// Step 2 guarantees the index is always in range for the array.
#pragma once
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename K, typename V>
class HashTable {
protected:
   int length = 0;   // number of items currently stored

   // Returns a non-negative hash code for the specified key.
   int Hash(const K& key) const {
      // The key type must have a std::hash<K> specialization.
      std::hash<K> hashFunctionObject;
      size_t hashCode = hashFunctionObject(key);
      // Set the high bit to 0 so the hash code is never negative.
      return (int)(hashCode & 0x7fffffff);
   }

   // Returns the smallest prime number >= n (used when resizing).
   static int NextPrime(int n) {
      if (n <= 2) return 2;
      if (n % 2 == 0) n++;
      while (true) {
         bool isPrime = true;
         for (int d = 3; (long long)d * d <= n; d += 2) {
            if (n % d == 0) { isPrime = false; break; }
         }
         if (isPrime) return n;
         n += 2;
      }
   }

public:
   virtual ~HashTable() {}

   // Inserts key/value. If the key exists its value is updated.
   virtual bool Insert(const K& key, const V& value) = 0;
   // Returns a pointer to the key's value, or nullptr if not found.
   virtual V* Get(const K& key) const = 0;
   // Removes the key; returns true if it was found.
   virtual bool Remove(const K& key) = 0;
   // Number of buckets.
   virtual int Capacity() const = 0;
   // Resize operation: more buckets, all existing items preserved. O(N).
   virtual void Resize(int newCapacity) = 0;
   // All items, in bucket order.
   virtual std::vector<std::pair<K, V>> Items() const = 0;
   // Prints every bucket and its contents (for learning/debugging).
   virtual void PrintTable(std::ostream& os) const = 0;

   int Length() const { return length; }
   bool Contains(const K& key) const { return Get(key) != nullptr; }

   // Common growth policy: next prime number >= 2 * N buckets.
   void Grow() { Resize(NextPrime(2 * Capacity())); }

   // Prints all items: prefix, then "key<kvSeparator>value" items joined by
   // itemSeparator, then suffix.
   void Print(std::ostream& os, const std::string& kvSeparator,
              const std::string& itemSeparator, const std::string& prefix,
              const std::string& suffix) const {
      os << prefix;
      bool first = true;
      for (const auto& item : Items()) {
         if (!first) os << itemSeparator;
         os << item.first << kvSeparator << item.second;
         first = false;
      }
      os << suffix;
   }
};
