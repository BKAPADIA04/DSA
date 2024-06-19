#include <bits/stdc++.h>
using namespace std;

long long int atMostCount(string s,int k) {
    int n = s.size();
    if (n == 0) {
        return 0;
    }
    int left = 0;
    int right = 0;
    int count = 0;
    long long int ans = 0ll;
    vector<int>freq(26,0);
    while(right < n) {
        freq[s[right] - 'a']++;
        if(freq[s[right] - 'a'] == 1) { // new element
            count++;
        }

        while(count > k) {
            freq[s[left] - 'a']--;
            if(freq[s[left] - 'a'] == 0) { // remove 
                count--;
            }
            left++;
        }

        ans += (right - left + 1);
        right++;
    }

    return ans;
}

long long int substrCount (string s, int k) {
    return (atMostCount(s,k) - atMostCount(s,k-1));
}

int main() {
    cout << substrCount("abaaca",1) << endl;
}