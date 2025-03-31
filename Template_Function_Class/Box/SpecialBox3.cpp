#include <iostream>
#include <string>

// Template class
template <typename T>
class Data {
private:
    T value;
public:
    Data(T val) : value(val) {}

    void print() { 
        std::cout << "Generic: " << value << std::endl; 
    }
};

// Specialization of print() for std::string
template <>
void Data<std::string>::print() {
    std::cout << "String Specialization: \"" << value << "\" (length: " 
              << value.length() << ")" << std::endl;
}

int main() {
    Data<int> intData(42);
    intData.print();  // Calls generic version

    Data<std::string> strData("Hello");
    strData.print();  // Calls specialized version

    return 0;
}
