#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int m = s.size(); int n = t.size();
    map<char,int>freq_map;
    for(int i = 0;i < n;i++) {
        freq_map[t[i]]++;
    }         
    int count = 0; int start_index = -1; int minlen = INT_MAX;
    int left = 0; int right = 0;

    while(right < m) {
        if(freq_map.find(s[right]) != freq_map.end() && freq_map[s[right]] > 0) {
            count += 1;
        }
        freq_map[s[right]]--;

        while(count == n) {
            if(right - left + 1 < minlen) {
                minlen = right-left+1;
                start_index = left;
            }
            freq_map[s[left]]++;
            if(freq_map[s[left]] > 0) {
                count -= 1;
            }
            left++;
        }
        right++;
    }

    return start_index == -1  ? "" : s.substr(start_index,minlen);
}

int main() {
    cout << minWindow("ADOBECODEBANC","ABC") << endl;
}