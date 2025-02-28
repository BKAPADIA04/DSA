class Solution {
public:

    int count(string word1,string word2,vector<vector<int>>&dp,int index1,int index2) {
        // if(index1 == 0 || index2 == 0) return 0;
        if(index1 == 0) return index2;
        if(index2 == 0) return index1;
        
        if(dp[index1][index2] != -1) return dp[index1][index2];

        int ans = 0;
        if(word1[index1-1] == word2[index2-1]) {
            ans = 0 + count(word1,word2,dp,index1-1,index2-1);
        }
        else {
            int replace = count(word1,word2,dp,index1-1,index2-1);
            int del = count(word1,word2,dp,index1-1,index2);
            int insert = count(word1,word2,dp,index1,index2-1);

            ans = 1 + min(replace,min(del,insert));
        }
        return dp[index1][index2] = ans;
    }


    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i = 1;i <= n;i++) {
        //     for(int j = 1;j <= m;j++) {
        //         int ans = 0;
        //         if(word1[i-1] == word2[j-1]) {
        //             ans = 0 + dp[i-1][j-1];
        //         }
        //         else {
        //             ans = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        //         }
        //         dp[i][j] = ans;
        //     }
        // }
        // return dp[n][m];

        return count(word1,word2,dp,n,m);
    }
};
