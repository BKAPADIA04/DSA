class Solution {
public:

    vector<vector<int>>dp;
    string s;

    int check(int l, int r) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        if(s[l] == s[r]) ans = check(l+1,r-1);
        else ans = 1 + min(check(l+1,r), check(l,r-1));

        return dp[l][r] = ans;
    }
    
    int almostPalindromic(string s) {
        int n = s.size();
        this->s = s;
        int ans = 0;
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        for(int i = 0;i < n;i++) {
            for(int j = i;j < n;j++) {
                int len = j - i + 1;
                if(len >= 2 && check(i,j) <= 1) ans = max(ans,len);
            }
        }
        return ans;
    }
};
