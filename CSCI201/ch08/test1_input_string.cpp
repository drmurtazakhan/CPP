// File name: test1_input_string.cpp
// compile: g++ test1_input_string.cpp -o test1_input_string.exe
// run: ./test1_input_string.exe

#include <iostream>

using namespace std;

int main()
{
    // Define arrays large enough to hold 30 characters plus the null terminator '\0'.
    char name1[31];
    char name2[31];

    // cin >> name1:
    // This is the extraction operator. It works by skipping any leading whitespace
    // characters and reading input until it encounters the next whitespace (like a space)
    // or newline character. It is ideal for single-word inputs, but because it stops
    // at the first space, it cannot read full sentences or names with spaces.
    // Additionally, it leaves the final newline character ('\n') in the input buffer.
    cout << "Enter a single word (no spaces): ";
    cin >> name1;
    cout << "First name stored: " << name1 << endl;

    // The extraction operator (>>) left a '\n' in the buffer. If we immediately
    // called cin.get(), that function would read the leftover '\n', assume the
    // user entered an empty line, and stop immediately. We use a temporary
    // variable to consume this newline character and clear the buffer.
    {
        char dummy;
        cin.get(dummy);
    }

    // cin.get(name2, 31):
    // This is a member function of the input stream that is specifically designed
    // to read character strings including spaces. The first argument is the
    // character array, and the second argument is the maximum number of characters
    // to read plus one (to reserve space for the null terminator). It stops reading
    // when it reaches the specified limit or encounters the newline character ('\n').
    // Unlike '>>', it does not skip leading whitespace and it properly handles
    // spaces within the input string.
    cout << "Enter a full name (with spaces): ";
    cin.get(name2, 31);
    cout << "Second name stored: " << name2 << endl;

    return 0;
}