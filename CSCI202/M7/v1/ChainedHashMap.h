// ChainedHashMap.h
#ifndef CHAINED_HASH_MAP_H
#define CHAINED_HASH_MAP_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

// Derived from Entry.h-Entry.html
template <typename K, typename V>
class Entry {
public:
    Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) {}
    const K& key() const { return _key; }
    const V& value() const { return _value; }
    void setValue(const V& v) { _value = v; }
private:
    K _key;
    V _value;
};

// Derived from HashMap.h-Class.html and HashMap.h-Put.html
template <typename K, typename V>
class ChainedHashMap {
public:
    typedef Entry<K, V> HashEntry;
    typedef std::list<HashEntry> Bucket;
    typedef std::vector<Bucket> BktArray;

    ChainedHashMap(int capacity = 101) : n(0), B(capacity) {}

    int size() const { return n; }
    bool empty() const { return n == 0; }

    // Implementation of the put logic from HashMap.h-Put.html
    void put(const K& k, const V& v) {
        int i = hashValue(k) % B.size();
        Bucket& bucket = B[i];
        
        // This loop performs the 'finder' utility logic
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key() == k) {
                it->setValue(v); // Replace value if key exists
                return;
            }
        }
        
        // This part performs the 'inserter' utility logic
        bucket.push_back(HashEntry(k, v));
        n++;
    }

    // Helper to retrieve values
    V get(const K& k) const {
        int i = hashValue(k) % B.size();
        const Bucket& bucket = B[i];
        for (const auto& entry : bucket) {
            if (entry.key() == k) return entry.value();
        }
        throw std::runtime_error("Key not found");
    }

private:
    int n;          // Number of entries
    BktArray B;     // Bucket array

    // Simple hash function for string keys
    int hashValue(const std::string& key) const {
        int h = 0;
        for (char c : key) h = (h << 5) | (h >> 27) ^ c; 
        return std::abs(h);
    }
};

#endif