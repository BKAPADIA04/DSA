class Solution {
public:

    int check(vector<int>&nums,int prev,int index,vector<vector<int>>&dp) {
        if(index == nums.size()) return nums[prev];
        if(index == nums.size()-1) return max(nums[prev],nums[index]);

        if(dp[prev][index] != -1) return dp[prev][index]; 
        
        int ans = INT_MAX;

        ans = min(ans,check(nums,index+1,index+2,dp) + max(nums[prev],nums[index]));
        ans = min(ans,check(nums,index,index+2,dp) + max(nums[prev],nums[index+1]));
        ans = min(ans,check(nums,prev,index+2,dp) + max(nums[index],nums[index+1]));

        return dp[prev][index] = ans;

    }

    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = check(nums,0,1,dp);
        return ans;
    }
};
