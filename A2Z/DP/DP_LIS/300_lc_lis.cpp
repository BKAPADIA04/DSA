class Solution {
public:

    int check(vector<int>& nums,int index,int prev_index,vector<vector<int>>&dp) {
        if(index >= nums.size()) return 0;

        if(dp[index][prev_index+1] != -1) return dp[index][prev_index+1];

        int notTaken = 0 + check(nums,index+1,prev_index,dp);

        int taken = 0;
        if(prev_index == -1 || nums[index] > nums[prev_index]) 
            taken = 1 + check(nums,index+1,index,dp);
        
        return dp[index][prev_index+1] = max(taken,notTaken);
    }

    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size() + 1,-1));
        // return check(nums,0,-1,dp);
        int n = nums.size();
        vector<int>dp(n,1); int answer = 1;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < i;j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i],dp[j] + 1);
                    answer = max(answer,dp[i]);
                }
            }
        }
        return answer;
    }
};