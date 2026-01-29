#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Base class: Normal Die
class Die {
protected:
    int sides;  // Number of sides

public:
    Die(int s = 6) : sides(s) {}  // Constructor with default 6 sides

    virtual int roll() {  // Virtual function for polymorphism
        return (rand() % sides) + 1;  // Random roll between 1 and sides
    }

    void print() {
        cout << "This is a " << sides << "-sided die." << endl;
    }
};

// Derived class: Loaded Die (favors higher rolls)
class LoadedDie : public Die {
public:
    LoadedDie(int s = 6) : Die(s) {}  // Constructor, uses Die's constructor

    int roll() override {  // Override roll() to favor higher values
        int biasedRoll = (rand() % (sides / 2)) + (sides / 2) + 1;
        return biasedRoll > sides ? sides : biasedRoll;  // Ensure within range
    }
};

// Test program
int main() {
    srand(time(0));  // Seed random number generator

    Die normalDie(6);
    LoadedDie loadedDie(6);

    cout << "Rolling a normal 6-sided die: " << normalDie.roll() << endl;
    cout << "Rolling a loaded 6-sided die: " << loadedDie.roll() << endl;

    return 0;
}
