// DoubleHashingHashTable.h
// Section 6.5: Double hashing.
//
// Uses two hash functions, H1 and H2:
//    bucketIndex = (H1(key) + i * H2(key)) mod tableSize,  i = 0, 1, 2, ...
//
// Here:  H1(key) = the key's hash code
//        H2(key) = SECOND_PRIME - hashCode % SECOND_PRIME   (range 1..prime)
//
// H2 must never return 0: if it did, the probing sequence would never move
// and collisions could not be resolved. Using a prime table size (Ex: 11)
// also makes the sequence visit every bucket.
//
// Insert, Get, Remove and Resize are inherited from linear probing; only the
// probing formula changes.
#pragma once
#include "LinearProbingHashTable.h"

template <typename K, typename V>
class DoubleHashingHashTable : public LinearProbingHashTable<K,V> {
private:
   int secondPrime;   // prime used by H2 (smaller than the table size)

protected:
   // H2: always in [1, secondPrime], never 0.
   int Hash2(int hashCode) const {
      return secondPrime - (hashCode % secondPrime);
   }

   // (H1 + i * H2) % tableSize
   int ProbeIndex(int hashCode, int i) const override {
      long long index = (long long)hashCode + (long long)i * Hash2(hashCode);
      return (int)(index % (long long)this->table.size());
   }

public:
   DoubleHashingHashTable(int initialCapacity = 11, int secondPrime = 7)
      : LinearProbingHashTable<K,V>(initialCapacity),
        secondPrime(secondPrime) { }
};
