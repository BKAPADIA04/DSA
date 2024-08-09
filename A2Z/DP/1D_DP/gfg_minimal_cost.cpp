#include <bits/stdc++.h>
using namespace std;

int minimizeCost(vector<int>& nums, int& k) {
    if(nums.size() == 1) return 0;
    vector<int>dp(nums.size(),INT_MAX);
    dp[0] = 0;
    for(int i = 1;i < nums.size();i++) {
        for(int j = 1;j <= k;j++) {
            if((i - j) >= 0) {
                dp[i] = min(dp[i],dp[i-j] + abs(nums[i] - nums[i-j]));
            }
        }
    }
    return dp[nums.size()-1];
}

int memoi(vector<int>&nums,int &k,vector<int>&dp,int i) {
    if(i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int min_steps = INT_MAX; int jumps = 0; int minSteps = INT_MAX;
    for(int j = 1;j <= k;j++) {
        if((i - j) >= 0) {
            jumps = memoi(nums,k,dp,i - j) + abs(nums[i] - nums[i-j]);
            minSteps = min(minSteps,jumps);
        }
    }
    return dp[i] = minSteps;
}

int main() {
    vector<int>nums = {10,30,40,50,20};
    vector<int>dp(nums.size(),-1);
    int k = 3;
    cout << minimizeCost(nums,k) << endl;

    cout << memoi(nums,k,dp,nums.size()-1) << endl;
}