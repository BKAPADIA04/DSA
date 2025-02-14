class Solution {
public:

    int check(vector<int>&nums,vector<vector<int>>&dp,int i,int j) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        // extract the last balloon first
        for(int k = i;k <= j;k++) {
            int tempo = nums[i-1] * nums[k] * nums[j+1];
            tempo += check(nums,dp,i,k - 1) + check(nums,dp,k + 1,j);
            maxi = max(maxi,tempo);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        int start = 1; int end = n;
        vector<vector<int>>dp(end+1,vector<int>(end+1,-1));
        return check(nums,dp,start,end);
        
    }
};