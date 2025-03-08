class Solution {
public:

    int check(vector<int>&nums,vector<vector<int>>&dp,int index,int time) {
        if(index == nums.size()) return 0;
        if(dp[index][time] != -1) return dp[index][time];

        int take = nums[index] * time + check(nums,dp,index+1,time+1);
        int notTake = check(nums,dp,index+1,time);

        return dp[index][time] = max(take,notTake);
    }

    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(nums.begin(),nums.end());
        return check(nums,dp,0,1);
    }
};

// class Solution {
// public:
//     int maxSatisfaction(vector<int>& satisfaction) {
//         sort(satisfaction.begin(), satisfaction.end());

//         int n = satisfaction.size();
//         int sum = 0;
//         int ans = 0;
//         int cur = 0;
//         for (int i = n - 1; i >= 0; i--) {
//             cur += sum + satisfaction[i];
//             sum += satisfaction[i];
//             ans = max(ans,cur);
//         }
//         return ans;
//     }
// };
