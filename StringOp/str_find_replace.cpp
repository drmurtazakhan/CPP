# include <iostream>
# include <string>
using namespace std;

int main()
{
    string::size_type index;
    string str = "Hello World!";
    cout << str << endl;

    // Find the first occurrence of "World"
    index = str.find("World");
    cout << "First occurrence of 'World' at index: " << index << endl;
    
    // start replacing str from position index, replace 5 characters with "Universe"
    str.replace(index, 5, "Universe"); 
    cout << str << endl; 

}