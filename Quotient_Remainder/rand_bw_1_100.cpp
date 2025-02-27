#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iostream>

int main() {
    srand(time(0));  // Seed the random number generator with the current time

    int random_value;   

    // rand(): Generates a pseudo-random integer between 0 and RAND_MAX.
    // Generate a random number between 1 and 100
    random_value = rand();
    std::cout << "Random number between 0 and RAND_MAX: " << random_value << std::endl;


    //Random numbers between min and max =>  rand() % (max - min + 1) + min
    
    // Generate a random number between 1 and 100
    random_value = rand() % (100 - 1 + 1) + 1;
    std::cout << "Random number between 1 and 100: " << random_value << std::endl;

    // Generate a random number between 0 and 100
    random_value = rand() % (100 - 0 + 1);
    std::cout << "Random number between 0 and 100: " << random_value << std::endl;

    // Generate a random boolean value
    bool flag = static_cast<bool>(rand() % 2);
    std::cout << "Random boolean: " << flag << std::endl;

    return 0;
}   