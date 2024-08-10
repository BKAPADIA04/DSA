#include <bits/stdc++.h>
using namespace std;

int rob_(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0],nums[1]);
    vector<int>dp(nums.size(),0);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i = 2;i < nums.size();i++) {
        dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
    }        
    return dp[nums.size()-1];
}
int rob(vector<int>& nums) {
    vector<int>temp1,temp2;
    for(int i = 0;i < nums.size()-1;i++) temp1.push_back(nums[i]);
    for(int i = 1;i < nums.size();i++) temp2.push_back(nums[i]);

    return max(rob_(temp1),rob_(temp2));      
}

int main() {
    vector<int>nums = {2,3,2};
    cout << rob(nums) << endl;
}