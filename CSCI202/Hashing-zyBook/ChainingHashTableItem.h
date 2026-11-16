// ChainingHashTableItem.h
// Section 6.2: an item (node) in a bucket's linked list.
#pragma once

template <typename K, typename V>
class ChainingHashTableItem {
public:
   K key;
   V value;
   ChainingHashTableItem<K,V>* next;   // next item in the same bucket

   ChainingHashTableItem(const K& itemKey, const V& itemValue) :
      key(itemKey), value(itemValue) {
      next = nullptr;
   }
};
