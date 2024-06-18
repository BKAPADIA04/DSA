#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main() {
    string s = "  Example   string   with   irregular  spaces.  ";
    
    // Step 1: Replace multiple spaces with a single space
    regex re("\\s+");
    s = regex_replace(s, re, " ");
    cout << s << s.size() << endl;
    // Step 2: Remove leading spaces
    s.erase(0, s.find_first_not_of(' '));
    cout << s << s.size() << endl;
    
    // Step 3: Remove trailing spaces
    s.erase(s.find_last_not_of(' ') + 1);
    cout << s << s.size() << endl;
    
    return 0;
}