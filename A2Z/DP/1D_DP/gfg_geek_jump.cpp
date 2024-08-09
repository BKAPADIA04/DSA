#include <bits/stdc++.h>
using namespace std;

int minimumEnergy(vector<int>& height, int n) {
    if(height.size() == 1) return 0;
    if(height.size() == 2) return abs(height[1] - height[0]);
    vector<int>dp(n,0);
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);
    for(int i = 2;i < n;i++) {
        dp[i] = min(dp[i-1] + (abs(height[i] - height[i-1])),dp[i-2] +(abs(height[i] - height[i-2])));
    }
    return dp[n-1];
}

int main() {
    vector<int>nums = {10,20,30,10};
    cout << minimumEnergy(nums,nums.size()) << endl; 
}