// File Name: anonymous_enum.cpp
// Compile: g++ anonymous_enum.cpp -o anonymous_enum.exe
// Run: ./anonymous_enum.exe
// This program demonstrates anonymous enumeration data types.

#include <iostream>
using namespace std;

int main()
{
    // Anonymous enumeration type:
    // The enum does not have a type name.
    // The variable "languages" is created directly.

    enum
    {
        ENGLISH,
        FRENCH,
        SPANISH,
        GERMAN,
        RUSSIAN
    } languages;

    enum
    {
        ENGLISH2,
        FRENCH2,
        SPANISH2,
        GERMAN2,
        RUSSIAN2
    } foreignLanguages;

    // Assign a value to languages.
    languages = SPANISH;

    // Assign a value to foreignLanguages.
    foreignLanguages = FRENCH2;

    cout << "Language value: "
         << languages << endl;

    cout << "Foreign Language value: "
         << foreignLanguages << endl;

    // The following statement is illegal because
    // languages and foreignLanguages are different types.
    //
    // Even though both enums have similar values,
    // the compiler treats them as separate data types.
    //
    // languages = foreignLanguages; // ERROR

    return 0;
}