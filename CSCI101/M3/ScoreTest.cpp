// compile: g++ -std=c++17 ScoreTest.cpp -o ScoreTest.exe
// run: ./ScoreTest.exe

#include <iostream>
using namespace std;

int main()
{
    // Hardcoded test score value
    int score = 70;

    cout << "Testing with Score: " << score << endl
         << endl;

    // ====================================================
    // METHOD 1: High to Low (Checking highest score first)
    // Uses >= with descending order (90 down to 60)
    // ====================================================
    cout << "--- Method 1: High to Low ---" << endl;

    if (score >= 90)
        cout << "The grade is A." << endl;
    else if (score >= 80)
        cout << "The grade is B." << endl;
    else if (score >= 70)
        cout << "The grade is C." << endl;
    else if (score >= 60)
        cout << "The grade is D." << endl;
    else
        cout << "The grade is F." << endl;

    cout << endl;

    // ====================================================
    // METHOD 2: Low to High (Checking lowest score first)
    // Uses < with ascending order (60 up to 90)
    // ====================================================
    cout << "--- Method 2: Low to High ---" << endl;

    if (score < 60)
        cout << "The grade is F." << endl;
    else if (score < 70)
        cout << "The grade is D." << endl;
    else if (score < 80)
        cout << "The grade is C." << endl;
    else if (score < 90)
        cout << "The grade is B." << endl;
    else
        cout << "The grade is A." << endl;

    return 0;
}