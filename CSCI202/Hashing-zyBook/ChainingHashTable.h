// ChainingHashTable.h
// Section 6.2: Chaining.
//
// Chaining handles collisions by keeping a linked list of items in each
// bucket. Get, Insert, and Remove each compute the bucket from the key, then
// search that bucket's list for the key.
#pragma once
#include "HashTable.h"
#include "ChainingHashTableItem.h"

template <typename K, typename V>
class ChainingHashTable : public HashTable<K,V> {
private:
   // One pointer per bucket: the head of that bucket's list (nullptr = empty).
   std::vector<ChainingHashTableItem<K,V>*> table;

   // Deletes every item in every bucket's list.
   void DeleteAllItems() {
      for (size_t i = 0; i < table.size(); i++) {
         ChainingHashTableItem<K,V>* item = table[i];
         while (item) {
            ChainingHashTableItem<K,V>* itemToDelete = item;
            item = item->next;        // advance BEFORE deleting
            delete itemToDelete;
         }
         table[i] = nullptr;
      }
   }

public:
   ChainingHashTable(int initialCapacity = 11) {
      table.resize(initialCapacity, nullptr);   // all buckets empty
   }

   // A table owns its items, so copying is disabled to avoid double deletes.
   ChainingHashTable(const ChainingHashTable&) = delete;
   ChainingHashTable& operator=(const ChainingHashTable&) = delete;

   virtual ~ChainingHashTable() {
      DeleteAllItems();
   }

   int Capacity() const override { return (int)table.size(); }

   // Inserts the key/value pair. If the key already exists, its value is
   // updated. Returns true.
   bool Insert(const K& key, const V& value) override {
      // Hash the key to get the bucket index
      int bucketIndex = this->Hash(key) % table.size();

      // Traverse the list searching for the key. If found, replace the value.
      ChainingHashTableItem<K,V>* currentItem = table[bucketIndex];
      ChainingHashTableItem<K,V>* previousItem = nullptr;
      while (currentItem) {
         if (key == currentItem->key) {
            currentItem->value = value;
            return true;
         }
         previousItem = currentItem;     // previousItem ends as the last item
         currentItem = currentItem->next;
      }

      // Key not found: append a new item to the bucket's list
      if (table[bucketIndex] == nullptr) {
         table[bucketIndex] = new ChainingHashTableItem<K,V>(key, value);
      }
      else {
         previousItem->next = new ChainingHashTableItem<K,V>(key, value);
      }
      this->length++;
      return true;
   }

   // Returns a pointer to the value if found, nullptr if not. The caller must
   // NOT delete the pointer: it points inside an item owned by the table. It
   // becomes invalid if the table is destroyed or the key is removed.
   V* Get(const K& key) const override {
      int bucketIndex = this->Hash(key) % table.size();

      ChainingHashTableItem<K,V>* item = table[bucketIndex];
      while (item) {
         if (key == item->key) {
            return &item->value;
         }
         item = item->next;
      }
      return nullptr;   // key not found
   }

   // Removes the key if found and returns true; otherwise returns false.
   bool Remove(const K& key) override {
      int bucketIndex = this->Hash(key) % table.size();

      ChainingHashTableItem<K,V>* currentItem = table[bucketIndex];
      ChainingHashTableItem<K,V>* previousItem = nullptr;
      while (currentItem) {
         if (key == currentItem->key) {
            if (previousItem == nullptr) {
               // Removing the list's first item: bucket points to the next one
               table[bucketIndex] = currentItem->next;
            }
            else {
               // Otherwise the previous item skips the removed item
               previousItem->next = currentItem->next;
            }
            delete currentItem;
            this->length--;
            return true;
         }
         previousItem = currentItem;
         currentItem = currentItem->next;
      }
      return false;   // key not found
   }

   // Resize: allocate more buckets and re-insert all items. O(N).
   void Resize(int newCapacity) override {
      if (newCapacity <= (int)table.size()) return;   // only grows
      std::vector<std::pair<K,V>> items = Items();    // save all items
      DeleteAllItems();
      table.assign(newCapacity, nullptr);
      this->length = 0;
      for (const auto& item : items) {
         Insert(item.first, item.second);   // bucket indices change!
      }
   }

   std::vector<std::pair<K,V>> Items() const override {
      std::vector<std::pair<K,V>> items;
      for (size_t i = 0; i < table.size(); i++) {
         for (auto* item = table[i]; item; item = item->next) {
            items.push_back({item->key, item->value});
         }
      }
      return items;
   }

   // Prints each bucket's list, e.g.  "6: (86, Paola) -> (16, Julie)"
   void PrintTable(std::ostream& os) const override {
      for (size_t i = 0; i < table.size(); i++) {
         os << i << ":";
         if (table[i] == nullptr) os << " empty";
         for (auto* item = table[i]; item; item = item->next) {
            os << " (" << item->key << ", " << item->value << ")";
            if (item->next) os << " ->";
         }
         os << std::endl;
      }
   }
};
