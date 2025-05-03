#include <bits/stdc++.h>
using namespace std;

int check(vector<int>&nums,vector<int>&dp,int k) {
  if(dp[k] != -1) return dp[k];
  int ans = 0; // ans = 0 -> Losing State and ans = 1 -> Winning State
  
  for(int i = nums.size()-1; i >= 0;i--) {
    int temp = -1;
    if(nums[i] <= k) temp = check(nums,dp,k-nums[i]);
    
    ans = ans | (temp == 0);
  }
  return dp[k] = ans;
}

int main() {
  int n,k; cin >> n >> k;
  vector<int>nums(n);
  for(int i = 0;i < n;i++) {
    cin >> nums[i];
  }
  
  vector<int>dp(k+1,-1);
  cout << ((check(nums,dp,k) == 1) ? "First" : "Second") << endl;
}