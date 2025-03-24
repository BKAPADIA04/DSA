class Solution {
public:

    int check(int ele, int index, int i, vector<vector<int>>&dp,vector<vector<int>>&queries) {
        if(ele == 0) return i;
        if(i == queries.size()) return INT_MAX;
        if(dp[i][ele] != -1) return dp[i][ele];
        if(queries[i][0] > index || queries[i][1] < index) {
            return check(ele,index,i+1,dp,queries);
        }
        int take = INT_MAX; int notTake = INT_MAX;
        if(queries[i][2] <= ele) take = check(ele - queries[i][2],index,i+1,dp,queries);
        notTake = check(ele,index,i+1,dp,queries);
        return dp[i][ele] = min(take,notTake);
    }


    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int mini = -1; int i;
        for(i = 0;i < n;i++) {
            vector<vector<int>>dp(queries.size(),vector<int>(nums[i]+1,-1));
            int ans = check(nums[i],i,0,dp,queries);
            if(ans == INT_MAX) return -1;
            mini = max(mini,ans);
        }
        return mini;
    }
};
