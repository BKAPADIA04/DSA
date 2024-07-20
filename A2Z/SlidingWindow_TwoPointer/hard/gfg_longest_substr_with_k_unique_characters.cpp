#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    map<char,int>freq_map;
    int temp_k = k;
    int n = s.size();
    int left = 0; int right = 0;
    int maxlen = -1;
    while(right < n) {
        if(freq_map.find(s[right]) == freq_map.end()) {
            k--;
        }
        freq_map[s[right]]++;

        if(k < 0) {
            freq_map[s[left]]--;
            if(freq_map[s[left]] == 0) {
                freq_map.erase(s[left]);
                k++;
            }
            left++;
        }

        // if(k==0) {
        if(freq_map.size() <= temp_k && k==0) {
            maxlen = max(maxlen,right-left+1);
        }
        right++;
    }
    return maxlen;
}

int main() {
    cout << longestKSubstr("aabacbebebe",3) << endl;
}