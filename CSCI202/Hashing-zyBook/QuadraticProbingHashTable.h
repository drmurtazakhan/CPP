// QuadraticProbingHashTable.h
// Section 6.4: Quadratic probing.
//
// bucketIndex = (H + c1*i + c2*i^2) mod tableSize,  i = 0, 1, 2, ...
// H is the hash code; c1 and c2 are programmer-defined non-negative integers.
//
// Insert, Get, Remove, Resize, and the empty-since-start /
// empty-after-removal logic are identical to linear probing, so this class
// only overrides the probing formula.
//
// Choosing c1 and c2: they should NOT be multiples of the number of buckets
// (Ex: c1 = c2 = 10 with 10 buckets always yields the same index). Common
// choices are c1 = 0, c2 = 1 and a prime number of buckets.
// c1 = 1, c2 = 0 would be plain linear probing.
#pragma once
#include "LinearProbingHashTable.h"

template <typename K, typename V>
class QuadraticProbingHashTable : public LinearProbingHashTable<K,V> {
private:
   int c1;
   int c2;

protected:
   // (H + c1*i + c2*i*i) % tableSize, using 64-bit math to avoid overflow.
   int ProbeIndex(int hashCode, int i) const override {
      long long index = (long long)hashCode + (long long)c1 * i +
                        (long long)c2 * i * i;
      return (int)(index % (long long)this->table.size());
   }

public:
   QuadraticProbingHashTable(int initialCapacity = 11, int c1 = 1, int c2 = 1)
      : LinearProbingHashTable<K,V>(initialCapacity), c1(c1), c2(c2) { }
};
