#include <iostream>
#include <string>
using namespace std;

int main()
{
    string::size_type index;
    string str = "Hello World, Hi World, My World.";
    string oldStr = "World";
    string newStr = "Universe";

    size_t strLength = str.size();
    size_t oldStrLength = oldStr.size();
    size_t newStrLength = newStr.size();

    cout << str << endl;

    // Find the first occurrence of oldStr
    index = str.find(oldStr);
    cout << "First occurrence of old string at index: " << index << endl;

    while (index < strLength)
    {
        // start replacing str from position index, replace oldStrLength characters with "Universe"
        str.replace(index, oldStrLength, newStr);
        index = str.find(oldStr, index + newStrLength);
    }
    cout << str << endl;
}