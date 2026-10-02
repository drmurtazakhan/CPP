// compile: g++ strcmp_examples.cpp -o strcmp_examples.exe
// run: ./strcmp_examples.exe

// This code demonstrates the usage of the strcmp function in C++ to compare two C-style strings (null-terminated character arrays). The strcmp function is part of the <cstring> header and returns an integer value based on the comparison of the two strings.

#include <iostream>
#include <cstring> // Required for strcmp

using namespace std;

int main()
{
    // Example 1: strcmp returns 0 (Strings are identical)
    char str1[] = "Apple";
    char str2[] = "Apple";
    int result1 = strcmp(str1, str2);
    cout << "strcmp(\"Apple\", \"Apple\"): " << result1 << " (Equal)" << endl;

    // Example 2: strcmp returns < 0 (s1 comes before s2 alphabetically)
    // 'A' has a smaller ASCII value than 'B'
    char str3[] = "Apple";
    char str4[] = "Banana";
    int result2 = strcmp(str3, str4);
    cout << "strcmp(\"Apple\", \"Banana\"): " << result2 << " (s1 < s2)" << endl;

    // Example 3: strcmp returns > 0 (s1 comes after s2 alphabetically)
    // 'C' has a larger ASCII value than 'A'
    char str5[] = "Cat";
    char str6[] = "Apple";
    int result3 = strcmp(str5, str6);
    cout << "strcmp(\"Cat\", \"Apple\"): " << result3 << " (s1 > s2)" << endl;

    return 0;
}