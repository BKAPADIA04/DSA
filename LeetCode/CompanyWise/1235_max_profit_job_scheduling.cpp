class Solution {
public:

    vector<vector<int>>nums;
    vector<int>dp;

    int check(int index) {
        if(index >= nums.size()) return 0;

        if(dp[index] != -1) return dp[index];

        int nextJob = lower_bound(nums.begin() + index + 1,nums.end(),vector<int>{nums[index][1],0,0}) - nums.begin();
        int take = nums[index][2] + check(nextJob);
        int notTake = check(index + 1);

        return dp[index] = max(take,notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        for(int i = 0;i < startTime.size();i++) {
            nums.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(nums.begin(),nums.end());
        dp = vector<int>(startTime.size(),-1);
        return check(0);
    }
};
