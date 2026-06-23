// Compare_Char.cpp
// compile: g++ Compare_Char.cpp -o Compare_Char.exe
// run:     ./Compare_Char.exe

#include <iostream>
using namespace std;

int main()
{
    // Comparing integers
    // 4 is less than 6, so this is TRUE. It will print 1.
    cout << "Is 4 < 6? Result: " << (4 < 6) << endl;

    // Comparing characters
    // '4' is less than '6', so this is TRUE. It will print 1.
    cout << "Is '4' < '6'? Result: " << ('4' < '6') << endl;

    // Comparing characters
    // 'R' comes BEFORE 'T' in the alphabet, so 'R' has a smaller ASCII value than 'T'.
    // Therefore, 'R' > 'T' is FALSE. It will print 0.
    cout << "Is 'R' > 'T'? Result: " << ('R' > 'T') << endl;

    // 3. Seeing the behind-the-scenes numbers
    // Let's print out the actual ASCII numbers for 'R' and 'T' to prove it.
    cout << "The ASCII number for 'R' is: " << (int)'R' << endl; // Prints 82
    cout << "The ASCII number for 'T' is: " << (int)'T' << endl; // Prints 84

    return 0;
}