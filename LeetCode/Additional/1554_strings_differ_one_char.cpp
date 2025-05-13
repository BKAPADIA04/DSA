#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    // Function checks if any two strings in the given dictionary differ by exactly one character
    bool differByOne(std::vector<std::string>& dict) {
        // Create an unordered set to keep track of unique patterns
        std::unordered_set<std::string> patterns;

        // Iterate through each word in the dictionary
        for (const auto& word : dict) {
            // Iterate through each character in the word
            for (size_t i = 0; i < word.size(); ++i) {
                // Make a copy of the word to create a pattern
                std::string pattern = word;
                // Replace the i-th character with a wildcard symbol '*'
                pattern[i] = '*';
              
                // Check if the pattern is already in the set
                if (patterns.count(pattern)) {
                    // If found, two words in the dict differ by one character
                    return true;
                }
                // If not found, insert the new pattern into the set
                patterns.insert(pattern);
            }
        }
        // If no such pair of words found, return false
        return false;
    }
};
