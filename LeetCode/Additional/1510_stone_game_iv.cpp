class Solution {
public:

    vector<int>dp;

    int check(int n) {
        if(n <= 0) return 0;
        if(dp[n] != -1) return dp[n];
        for(int i = 1;i * i <= n;i++) {
            if(check(n - i * i) == 0) return dp[n] = 1; 
        }
        return dp[n] = 0;
    }

    bool winnerSquareGame(int n) {
        dp = vector<int>(1e5+10,-1);
        return check(n);
    }
};
