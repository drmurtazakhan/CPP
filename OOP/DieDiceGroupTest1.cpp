#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Base class: Normal Die
class Die {
private:
    int sides;  // Number of sides on the die

public:
    Die(int s = 6) : sides(s) {}  // Constructor with default 6 sides

    int roll() {  // Generate a random roll
        return (rand() % sides) + 1;  // Random number between 1 and sides
    }

    int getSides() { return sides; }  // Get the number of sides
};

// DiceGroup class: A collection of dice
class DiceGroup {
private:
    vector<Die> dice;  // Vector to store multiple dice

public:
    DiceGroup(int numDice, int sides) {  // Constructor
        for (int i = 0; i < numDice; i++) {
            dice.push_back(Die(sides));  // Add 'numDice' dice with 'sides' sides
        }
    }

    void rollAll() {  // Rolls all dice and prints results
        cout << "Rolling all dice..." << endl;
        for (size_t i = 0; i < dice.size(); i++) {
            cout << "Die " << i + 1 << ": " << dice[i].roll() << endl;
        }
    }
};

// Test program
int main() {
    srand(time(0));  // Seed the random number generator

    DiceGroup myDiceGroup(5, 6);  // Create a group of 5 six-sided dice

    myDiceGroup.rollAll();  // Roll all dice and display results

    return 0;
}
