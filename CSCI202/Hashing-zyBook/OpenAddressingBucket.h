// OpenAddressingBucket.h
// Section 6.3: a bucket in an open addressing table.
//
// A bucket is in one of three states:
//   1. occupied (holds a key and value),
//   2. empty-since-start (never used since the table was created), or
//   3. empty-after-removal (an item was removed from it).
// Searching stops at empty-since-start but NOT at empty-after-removal.
#pragma once

template <typename K, typename V>
class OpenAddressingBucket {
public:
   K* key;
   V* value;

   // Creates the special "empty" buckets (key and value are null).
   OpenAddressingBucket() {
      key = nullptr;
      value = nullptr;
   }

   // Creates an occupied bucket (copies of key and value are allocated).
   OpenAddressingBucket(const K& bucketKey, const V& bucketValue) {
      key = new K(bucketKey);
      value = new V(bucketValue);
   }

   OpenAddressingBucket(const OpenAddressingBucket&) = delete;
   OpenAddressingBucket& operator=(const OpenAddressingBucket&) = delete;

   virtual ~OpenAddressingBucket() {
      if (key) delete key;
      if (value) delete value;
   }

   // Two special bucket types exist. All empty buckets in all tables of this
   // type POINT to one of these two shared static instances.
   inline static OpenAddressingBucket<K,V> EMPTY_SINCE_START;
   inline static OpenAddressingBucket<K,V> EMPTY_AFTER_REMOVAL;

   // The address (this) is compared, not key/value: both special buckets have
   // null key and value, so only their addresses tell them apart.
   bool IsEmpty() const {
      return this == &EMPTY_SINCE_START || this == &EMPTY_AFTER_REMOVAL;
   }
   bool IsEmptyAfterRemoval() const { return this == &EMPTY_AFTER_REMOVAL; }
   bool IsEmptySinceStart() const { return this == &EMPTY_SINCE_START; }
};
