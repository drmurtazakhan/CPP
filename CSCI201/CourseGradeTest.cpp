#include <iostream>
using namespace std;

// Function Prototype
char courseGrade(int score);

int main() {
    int studentScore;
    
    cout << "Enter the student's score (0-100): ";
    cin >> studentScore;

    // Call the function and store the result
    char letterGrade = courseGrade(studentScore);

    cout << "The letter grade is: " << letterGrade << endl;

    return 0;
}

// Function Definition based on your image
char courseGrade(int score) {
    // Dividing by 10 allows us to use single digits in the switch
    switch (score / 10) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return 'F';
        case 6:
            return 'D';
        case 7:
            return 'C';
        case 8:
            return 'B';
        case 9:
        case 10:
            return 'A';
        default:
            return 'X'; // For invalid scores
    }
}