class Solution {
public:

    bool check(int index,int target,vector<int>&nums,vector<vector<int>>&dp) {
        if(target == 0) {
            return true;
        }

        if(index < 0) return false;

        if(dp[index][target] != -1) return dp[index][target];
        // bool include = check(index-1,target - nums[index],nums,dp);
        bool exclude = check(index-1,target,nums,dp);
        bool include = false;
        if(nums[index] <= target)
            include = check(index-1,target - nums[index],nums,dp);

        return dp[index][target] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum & 1) return false;
        else {
            int half = sum/2;
            vector<vector<int>>dp(nums.size(),vector<int>(100000,-1));
            return check(nums.size()-1,half,nums,dp);
        }
    }
};