#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    // map<char,int>m;
    vector<int>m(256,-1);
    int l = 0;
    int r = 0;
    int max_length = 0;
    while(r < n) {
        // if(m.find(s[r]) != m.end()) {
        //     l = max(l,m[s[r]] + 1);
        // }
        if(m[s[r]] != -1) {
            l = max(l,m[s[r]] + 1);
        }
        m[s[r]] = r;
        max_length = max(max_length,r - l + 1);
        r++;
    }       
    return max_length;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
}