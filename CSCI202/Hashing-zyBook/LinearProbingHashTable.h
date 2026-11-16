// LinearProbingHashTable.h
// Section 6.3: Linear probing (a type of open addressing).
//
// On a collision, start at the key's mapped bucket and linearly check the
// following buckets (wrapping around) until an empty bucket is found:
//    bucketIndex = (hashCode + i) % tableSize,   i = 0, 1, 2, ...
//
// The probing formula is isolated in the virtual function ProbeIndex() so that
// QuadraticProbingHashTable (6.4) and DoubleHashingHashTable (6.5) can reuse
// Insert/Get/Remove and only replace the formula.
#pragma once
#include "HashTable.h"
#include "OpenAddressingBucket.h"

template <typename K, typename V>
class LinearProbingHashTable : public HashTable<K,V> {
protected:
   typedef OpenAddressingBucket<K,V> Bucket;
   // One pointer per bucket; empty buckets point to a shared static instance.
   std::vector<Bucket*> table;

   // Bucket index for probe number i (the "probing sequence").
   // Linear probing: (hashCode + i) % tableSize.
   virtual int ProbeIndex(int hashCode, int i) const {
      return (int)(((long long)hashCode + i) % (long long)table.size());
   }

   // Frees all occupied buckets (never the shared static empty buckets).
   void DeleteAllBuckets() {
      for (size_t i = 0; i < table.size(); i++) {
         if (!table[i]->IsEmpty()) {
            delete table[i];   // destructor frees the key and value
         }
         table[i] = &Bucket::EMPTY_SINCE_START;
      }
   }

public:
   LinearProbingHashTable(int initialCapacity = 11) {
      // Every bucket starts as empty-since-start (all share one object).
      table.resize(initialCapacity, &Bucket::EMPTY_SINCE_START);
   }

   LinearProbingHashTable(const LinearProbingHashTable&) = delete;
   LinearProbingHashTable& operator=(const LinearProbingHashTable&) = delete;

   virtual ~LinearProbingHashTable() {
      DeleteAllBuckets();
   }

   int Capacity() const override { return (int)table.size(); }

   // Inserts key/value. If the key exists, its value is updated. Returns true
   // if inserted/updated, false if all buckets are occupied (a full table).
   // (Real implementations usually resize instead; see Resize()/Grow().)
   bool Insert(const K& key, const V& value) override {
      int hashCode = this->Hash(key);

      // Step 1: search for the key. If found, update the bucket's value.
      for (int i = 0; i < (int)table.size(); i++) {
         int bucketIndex = ProbeIndex(hashCode, i);

         // Empty-since-start: key cannot be further along the sequence
         if (table[bucketIndex]->IsEmptySinceStart()) {
            break;
         }
         // Empty-after-removal buckets are skipped, not stopped at
         if (!table[bucketIndex]->IsEmptyAfterRemoval()) {
            if (key == *table[bucketIndex]->key) {
               delete table[bucketIndex]->value;
               table[bucketIndex]->value = new V(value);
               return true;
            }
         }
      }

      // Step 2: key not in table. Probe again and use the FIRST empty bucket
      // (either empty kind is fine).
      for (int i = 0; i < (int)table.size(); i++) {
         int bucketIndex = ProbeIndex(hashCode, i);
         if (table[bucketIndex]->IsEmpty()) {
            table[bucketIndex] = new Bucket(key, value);
            this->length++;
            return true;
         }
      }
      return false;   // no empty bucket found
   }

   // Returns a pointer to the value, or nullptr if the key is not found.
   V* Get(const K& key) const override {
      int hashCode = this->Hash(key);
      for (int i = 0; i < (int)table.size(); i++) {
         int bucketIndex = ProbeIndex(hashCode, i);

         if (table[bucketIndex]->IsEmptySinceStart()) {
            return nullptr;   // key is not in the table
         }
         if (!table[bucketIndex]->IsEmptyAfterRemoval()) {
            if (key == *table[bucketIndex]->key) {
               return table[bucketIndex]->value;
            }
         }
      }
      return nullptr;   // probed all buckets without a match
   }

   // Searches for the key; if found, removes it and marks the bucket
   // empty-after-removal (NOT empty-since-start, or later searches would stop
   // too early). Returns true if removed.
   bool Remove(const K& key) override {
      int hashCode = this->Hash(key);
      for (int i = 0; i < (int)table.size(); i++) {
         int bucketIndex = ProbeIndex(hashCode, i);

         if (table[bucketIndex]->IsEmptySinceStart()) {
            return false;   // key is not in the table
         }
         if (!table[bucketIndex]->IsEmptyAfterRemoval()) {
            if (key == *table[bucketIndex]->key) {
               delete table[bucketIndex];
               table[bucketIndex] = &Bucket::EMPTY_AFTER_REMOVAL;
               this->length--;
               return true;
            }
         }
      }
      return false;   // key not found
   }

   // Resize: allocate more buckets and re-insert all items. O(N).
   void Resize(int newCapacity) override {
      if (newCapacity <= (int)table.size()) return;   // only grows
      std::vector<std::pair<K,V>> items = Items();    // save all items
      DeleteAllBuckets();
      table.assign(newCapacity, &Bucket::EMPTY_SINCE_START);
      this->length = 0;
      for (const auto& item : items) {
         Insert(item.first, item.second);
      }
   }

   std::vector<std::pair<K,V>> Items() const override {
      std::vector<std::pair<K,V>> items;
      for (size_t i = 0; i < table.size(); i++) {
         if (!table[i]->IsEmpty()) {
            items.push_back({*table[i]->key, *table[i]->value});
         }
      }
      return items;
   }

   // Prints each bucket: its item, or the kind of empty bucket.
   void PrintTable(std::ostream& os) const override {
      for (size_t i = 0; i < table.size(); i++) {
         os << i << ": ";
         if (table[i]->IsEmptySinceStart()) os << "empty-since-start";
         else if (table[i]->IsEmptyAfterRemoval()) os << "empty-after-removal";
         else os << "(" << *table[i]->key << ", " << *table[i]->value << ")";
         os << std::endl;
      }
   }
};
