#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    // starting from the center and moving towards the boundaries

    int start = 0, end = 1;// end = length of the substring
    int low,high;

    for(int i = 0;i < n;i++) {
        // even length substring
        low = i - 1;
        high = i;
        while(low >= 0 && high < n && s[low] == s[high]) {
            if(high - low + 1 > end) {
                start = low;
                end = high - low + 1; 
            }
            low--;
            high++;
        }

        // odd length substring
        low = i - 1;
        high = i + 1;
        while(low >= 0 && high < n && s[low] == s[high]) {
            if(high - low + 1 > end) {
                start = low;
                end = high - low + 1; 
            }
            low--;
            high++;
        }
    }
    return s.substr(start,end);
}

int main() {
    cout << longestPalindrome("a") << endl;
}