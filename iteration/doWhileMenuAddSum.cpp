#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
    short c;
    long num1, num2, add, sub;

    do {
        cout << "1 - Add (num 1 + num2) " << endl;
        cout << "2 - Subtract (num 1 - num2) " << endl;
        cout << "3 - Quit" << endl;
        cout << "Enter a number: ";
        cin >> c;

        if (c==1)
        {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            add = num1 + num2;
            cout << "Answer: " << add << endl;
        }

        if (c==2)
        {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            sub = num1 - num2;
            cout << "Answer: " << sub << endl;
        }

    } while (c != 3);

    return 0;
}
