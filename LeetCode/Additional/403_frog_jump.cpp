class Solution {
public:

    bool check(vector<int>&stones, vector<vector<int>>&dp, int index, int k) {
        if(index == (stones.size() - 1)) return true;
        if(index >= stones.size()) return false;

        if(dp[index][k] != -1) return dp[index][k];

        bool ans1 = false; bool ans2 = false; bool ans3 = false;
        int curr = stones[index];
        if(k - 1 > 0) {
            int nextPosn = curr + (k - 1);
            int lower = lower_bound(stones.begin(),stones.end(),nextPosn) - stones.begin();
            if(lower != stones.size() && stones[lower] == nextPosn) {
                ans1 = check(stones,dp,lower,k - 1);
            }
        }
        if(k > 0) {
            int nextPosn = curr + k;
            int lower = lower_bound(stones.begin(),stones.end(),nextPosn) - stones.begin();
            if(lower != stones.size() && stones[lower] == nextPosn) {
                ans2 = check(stones,dp,lower,k);
            }
        }
        if(k + 1 > 0) {
            int nextPosn = curr + (k + 1);
            int lower = lower_bound(stones.begin(),stones.end(),nextPosn) - stones.begin();
            if(lower != stones.size() && stones[lower] == nextPosn) {
                ans3 = check(stones,dp,lower,k + 1);
            }
        }
        return dp[index][k] = ans1 || ans2 || ans3;
    }


    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        int n = stones.size();
        vector<vector<int>>dp(n + 1,vector<int>(n + 1,-1));
        return check(stones,dp,1,1);
    }
};
