#include <bits/stdc++.h>
using namespace std;

// DP

bool checkValidString(string s) {
    int n = s.size();
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    dp[0][0] = true;
    for(int i = 1;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(s[i] == '(') {
                dp[i][j] = 
            }
            else if(s[i] == ')') {

            }
            else {

            }
        }
    }
    return (dp[n-1][n-1] == 0);
}