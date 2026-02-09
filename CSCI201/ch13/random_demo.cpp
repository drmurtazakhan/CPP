// File name: random_demo.cpp
#include <iostream>
#include <random> // Essential for C++11 random functions
using namespace std;

int main() {
    // 1. Create a "Seed"
    // This uses the computer's hardware to create a starting point
    random_device rd; 

    // 2. The Engine (The "Crank")
    // mt19937 is the most popular engine (Mersenne Twister)
    mt19937 engine(rd());

    // 3. The Distributors (The "Shapes")
    
    // This one makes whole numbers (e.g., for a game)
    uniform_int_distribution<int> intDist(1, 100);

    // This one makes decimal numbers (e.g., for probability)
    uniform_real_distribution<double> realDist(0.0, 1.0);

    // 4. Generate the numbers
    // We pass the engine TO the distribution
    int randomInt = intDist(engine);
    double randomDouble = realDist(engine);

    cout << "Random Integer (1-100): " << randomInt << endl;
    cout << "Random Double (0-1): " << randomDouble << endl;

    return 0;
}