// regex_test2.cpp
// Compilation: g++ regex_test2.cpp -o regex_test2.exe -mconsole
// Execution: .\regex_test2.exe

#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "The campus zip code is 46408.";
    
    // Pattern: \d{5} looks for exactly 5 digits in a row
    std::regex zip_pattern(R"(\d{5})");
    
    // std::smatch holds the results of the search
    std::smatch results;

    if (std::regex_search(text, results, zip_pattern)) {
        // results[0] contains the entire matched string
        std::cout << "Match found: " << results[0] << std::endl;
    } else {
        std::cout << "No 5-digit zip code detected." << std::endl;
    }

    return 0;
}