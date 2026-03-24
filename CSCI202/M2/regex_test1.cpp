// regex_test1.cpp
// Compilation: g++ regex_test1.cpp -o regex_test1.exe
// Execution: .\regex_test1.exe
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "My zip code is 46307.";
    
    // Using a Raw String Literal for the pattern
    // \d{5} matches exactly five digits
    std::regex zip_pattern(R"(\d{5})");

    if (std::regex_search(text, zip_pattern)) {
        std::cout << "Found a valid 5-digit zip code!" << std::endl;
    } else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}
