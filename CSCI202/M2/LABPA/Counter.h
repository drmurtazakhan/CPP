#ifndef COUNTER_H
#define COUNTER_H

// The Counter class manages a simple non-negative integer
class Counter {
public:
    // Function prototypes
    void increment();       // Adds 1 to count
    void decrement();       // Subtracts 1 from count (not below 0)
    void reset();           // Sets count to 0
    int getCount() const;   // Returns current count (const: does not modify data)

private:
    // In-line initialization (C++11) sets default to 0
    int count = 0;
};

#endif