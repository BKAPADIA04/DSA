class Solution {
public:

    char next(char ch) {
        if(ch == 'z') return 'a';
        return ch + 1;
    }

    char prev(char ch) {
        if(ch == 'a') return 'z';
        return ch - 1;
    }

    int checker(char ch1,char ch2,int k) {
        
        int next_dist = abs(ch1 - ch2);

        if(min(next_dist,26 - next_dist) > k) return -1;
        return min(next_dist,26 - next_dist);
    }

    int check(string &s,int k,int i,int j,vector<vector<vector<int>>>&dp) {
        if(i == j) return 1;
        if(i > j) return 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];
        int ans = 0;
        if(s[i] == s[j]) {
            ans = max(ans,2 + check(s,k,i+1,j-1,dp));
        }
        else {
            ans = max(check(s,k,i+1,j,dp),check(s,k,i,j-1,dp));

            int temp = checker(s[i],s[j],k);
            if(temp != -1 && temp <= k) ans = max(ans,2 + check(s,k - temp ,i+1,j-1,dp));
        }
        return dp[i][j][k] = ans;
    }

    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans = check(s,k,0,n-1,dp);
        return ans;
    }
};
