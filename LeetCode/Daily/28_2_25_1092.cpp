class Solution {
public:
    void print(vector<vector<int>>dp) {
        for(auto it:dp) {
            for(auto it1:it) {
                cout << it1 << " ";
            }
            cout << endl;
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int i = n; int j = m;
        string ans = "";
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans += str1[i-1];
                i--;
            }
            else {
                ans += str2[j-1];
                j--;
            }
            // cout << ans << endl;
        }
        // cout << i << " " << j << endl;
        while(i > 0) {
            ans += str1[i-1]; i--;
        }

        while(j > 0) {
            ans += str2[j-1]; j--;
        }
        // cout << dp[n][m] << endl;
        // print(dp);
        reverse(ans.begin(),ans.end());
        return ans;
        // return dp[n-1][m-1];
    }
};






















