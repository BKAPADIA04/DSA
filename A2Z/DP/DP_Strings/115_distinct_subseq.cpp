class Solution {
public:

    // vector<vector<int>>dp;
    int mod = 1e9 + 7;

    // int check(string str1, string str2, int i, int j) {
    //     if(j < 0) return 1;
    //     if(i < 0) {
    //         if(j < 0) return 1;
    //         return 0;
    //     } 

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int count = check(str1,str2,i - 1,j) % mod;
    //     if(str1[i] == str2[j]) {
    //         count = (count + check(str1,str2,i - 1, j - 1)) % mod;
    //     }
    //     return dp[i][j] = count % mod;
    // }

    int numDistinct(string str1, string str2) {
        int n = str1.size(); int m = str2.size();
        // dp = vector<vector<int>>(n,vector<int>(m,-1));
        // return check(str1,str2,n - 1,m - 1);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialize the first row: empty string s2 can be matched with any non-empty s1 in one way
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Initialize the first column: s1 can't match any non-empty s2
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 0;
        }

        // Fill in the DP array
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    // If the characters match, we have two options:
                    // 1. Match the current characters and move diagonally (dp[i-1][j-1])
                    // 2. Leave the current character in s1 and match s2 with the previous characters (dp[i-1][j])
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                } else {
                    // If the characters don't match, we can only leave the current character in s1
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The value at dp[n][m] contains the count of distinct subsequences
        return dp[n][m];
    }
};1
