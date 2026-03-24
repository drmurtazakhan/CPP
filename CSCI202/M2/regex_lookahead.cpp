// regex_lookahead.cpp
// Compilation: g++ regex_lookahead.cpp -o regex_lookahead.exe
// Execution: .\regex_lookahead.exe

#include <iostream>
#include <regex>    // Required for std::regex, std::smatch, and std::sregex_iterator
#include <string>
#include <iterator> // Required for std::distance

int main() {
    // 1. The Source String: Our target text containing various "q" words.
    std::string text = "test quiet queen Iraq";

    // 2. The Regex Pattern:
    // \b        -> Word boundary (ensures we start at the beginning of a word)
    // q         -> Matches the literal character 'q'
    // (?=u)     -> Positive Lookahead: "Is the next character a 'u'?" 
    //              (This check is 'zero-width', meaning it doesn't consume the 'u')
    // \w* -> Matches any remaining "word" characters (letters/digits) in that word
    std::regex pattern(R"(\bq(?=u)\w*)");

    // 3. The Iterators:
    // sregex_iterator allows us to step through the string to find ALL matches,
    // not just the first one (which is what std::regex_search does).
    
    // 'words_begin' starts the search from the beginning of our string.
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
    
    // 'words_end' is a default-constructed iterator representing the "end of matches".
    auto words_end = std::sregex_iterator();

    // 4. Counting Matches:
    // std::distance calculates how many steps are between the start and end iterators.
    std::cout << "Search Results:" << std::endl;
    std::cout << "Total matches found: " << std::distance(words_begin, words_end) << "\n" << std::endl;

    // 5. The Extraction Loop:
    // We iterate from the first match found until we reach the 'end' marker.
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        
        // Dereferencing the iterator (*i) gives us a std::smatch object.
        // This object contains the details of the specific match found in this step.
        std::smatch match = *i;
        
        // match.str() returns the actual substring that was matched (e.g., "quiet").
        // match.position() gives the starting index within the original string.
        std::cout << "Match: " << match.str() 
                  << " (Found at index: " << match.position() << ")" << std::endl;
    }

    return 0;
}