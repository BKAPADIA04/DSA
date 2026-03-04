class Solution {
public:

    int check(int target,vector<int>&dp) {
        if(target == 0) return 0;
        // if(target == 1) return 1;
        int tmp = target + 1;
        if((tmp & (tmp-1)) == 0) {
            return dp[target] = __builtin_popcount(target);
        }   

        if(dp[target] != -1) return dp[target];

        // cout << target << endl;

        int logg = log2(target) + 1;
        int ans = check((1 << logg) - 1 - target, dp) + logg + 1;
        for(int m = 0;m < logg - 1;m++) {
            int dist = target - (1 << (logg - 1)) + (1 << m);
            ans = min(ans, check(dist,dp) + logg + m + 1);
        }
        
        return dp[target] = ans;
    }

    int racecar(int target) {
        vector<int>dp(target+1,-1);
        return check(target,dp);
    }
};
