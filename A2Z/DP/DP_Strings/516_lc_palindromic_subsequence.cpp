#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// memory error
    int check(string str,int i,int j,vector<vector<int> >&dp) {
        if(i == j) return 1;

        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(str[i] == str[j]) {
            return dp[i][j] = 2 + check(str,i+1,j-1,dp);
        }
        else 
            return dp[i][j] = max(check(str,i+1,j,dp),check(str,i,j-1,dp));
    }


    int longestCommonSubsequence(string str1, string str2) {
        int n = str1.size(); int m = str2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>prev(m+1),curr(m+1);
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(str1[i-1] == str2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size(); string temp = s; reverse(temp.begin(),temp.end());
        // vector<vector<int> >dp(n,vector<int>(n,-1));
        return longestCommonSubsequence(s,temp);
    }
};