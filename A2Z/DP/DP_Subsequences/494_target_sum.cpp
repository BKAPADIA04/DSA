class Solution {
public:

    // vector<unordered_map<int,int>> dp;
    int check(vector<int>& nums, int n,int target,int index,int sum,vector<unordered_map<int,int>> &dp) {
        if(index == n) {
            if(target == sum) return 1;
            else return 0;
        }
        if(dp[index].find(sum) != dp[index].end()) {
            return dp[index][sum];
        }
        int plus = check(nums,n,target,index+1,sum+nums[index],dp);
        int minus = check(nums,n,target,index+1,sum-nums[index],dp);

        return dp[index][sum] = plus + minus;
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        int totSum = accumulate(arr.begin(),arr.end(),0);
        int searchSum = (totSum - d)/2;
        
        if(totSum-d <0 || (totSum-d)%2 ) return 0;
        vector<vector<int>>dp(n,vector<int>(searchSum+1,0));
        
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        if(arr[0] != 0 && arr[0] <= searchSum) dp[0][arr[0]] = 1;
        
        for(int i = 1;i < n;i++) {
            for(int sum = 0;sum <= searchSum;sum++) {
                int notTaken = dp[i-1][sum];
                int taken = 0;
                if(arr[i] <= sum) {
                    taken = dp[i-1][sum-arr[i]];
                }
                // cout << dp[n-1][searchSum] << endl;
                dp[i][sum] = (notTaken + taken);
            }
        }
        return dp[n-1][searchSum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // int totSum = accumulate(nums.begin(),nums.end(),0);
        // vector<int>dp(1001,-1);
        // unordered_map<pair<int,int>,int>umap;
        vector<unordered_map<int,int>> dp(n);
        return check(nums,n,target,0,0,dp);
        // return countPartitions(n,target,nums);
    }
};