#include <bits/stdc++.h>
using namespace std;
// number of subsequences
int countSubsequences(string str) {
    int n = str.size();
    vector<int>dp_char_pos(26,-1);
    vector<int>dp(n+1,0);
    dp[0] = 1; // single character (first)
    for(int i = 1;i <= n;i++) {
        dp[i] = 2 * dp[i-1];
        if(dp_char_pos[str[i-1] - 'a'] != -1) {
            dp[i] = dp[i] - dp[dp_char_pos[str[i-1] - 'a']];
        } 
        dp_char_pos[str[i-1] - 'a'] = i - 1;
    }
    return dp[n];
}


string betterString(string str1, string str2) {
    if(countSubsequences(str1) - countSubsequences(str2) >= 0) return str1;
    else return str2;
}

int main() {
    string str = betterString("gboubwd","bekoilx");
    cout << str << endl;
}