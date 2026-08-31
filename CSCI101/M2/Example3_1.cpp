// Example3_1.cpp
// compile: g++ Example3_1.cpp -o Example3_1.exe
// run:     ./Example3_1.exe

// Demonstration of the extraction operator (>>
// Use the exact inputs shown in the textbook table.

#include <iostream>
using namespace std;

int main()
{
     int a, b;
     double z;
     char ch;

     // Statement 1
     cout << "Statement 1: cin >> ch;\n";
     cout << "Enter A: ";
     cin >> ch;
     cout << "Value stored: ch = '" << ch << "'\n\n";

     // Statement 2
     cout << "Statement 2: cin >> ch;\n";
     cout << "Enter AB: ";
     cin >> ch;
     cout << "Value stored: ch = '" << ch
          << "' (B remains in the input stream)\n\n";

     // Read the next character from the input buffer
     cin >> ch;
     cout << "The next input operation reads: " << ch << endl;

     // Statement 3
     cout << "Statement 3: cin >> a;\n";
     cout << "Enter 48: ";
     cin >> a;
     cout << "Value stored: a = " << a << "\n\n";

     // Statement 4
     cout << "Statement 4: cin >> a;\n";
     cout << "Enter 46.35: ";
     cin >> a;
     cout << "Value stored: a = " << a
          << " (.35 is not stored in a)\n\n";

     // Statement 5
     cout << "Statement 5: cin >> z;\n";
     cout << "Enter 74.35: ";
     cin >> z;
     cout << "Value stored: z = " << z << "\n\n";

     // Statement 6
     cout << "Statement 6: cin >> z;\n";
     cout << "Enter 39: ";
     cin >> z;
     cout << "Value stored: z = " << z << "\n\n";

     // Statement 7
     cout << "Statement 7: cin >> z >> a;\n";
     cout << "Enter 65.78 38: ";
     cin >> z >> a;
     cout << "Values stored: z = " << z
          << ", a = " << a << "\n\n";

     // Statement 8
     cout << "Statement 8: cin >> a >> b;\n";
     cout << "Enter 4 60: ";
     cin >> a >> b;
     cout << "Values stored: a = " << a
          << ", b = " << b << "\n\n";

     // Statement 9
     cout << "Statement 9: cin >> a >> z;\n";
     cout << "Enter 46 32.4 68: ";
     cin >> a >> z;
     cout << "Values stored: a = " << a
          << ", z = " << z << endl;
     cout << "The value 68 remains in the input stream.\n";

     return 0;
}