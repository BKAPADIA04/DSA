#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string str1, string str2) {
    int n = str1.size(); int m = str2.size();
    vector<vector<int> >dp(n+1,vector<int>(m+1,0));
    // vector<int>prev(m+1),curr(m+1);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i = n; int j = m;
    string str = "";
    while(i > 0 && j > 0) {
        if(str1[i-1] == str2[j-1]) {
            str += str1[i - 1];
            i = i - 1; j = j - 1;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            str += str1[i-1];
            i = i - 1;
        }
        else {
            str += str2[j-1];
            j = j - 1;
        }
    }

    while(i > 0) {
        str += str1[--i];
    }
    while(j > 0) {
        str += str2[--j];
    }
    reverse(str.begin(),str.end());
    return str;
}   

int main() {
    cout << longestCommonSubsequence("abac","cab") << endl;
}