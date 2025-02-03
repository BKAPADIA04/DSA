#include <bits/stdc++.h>
using namespace std;

int check(vector<int>&nums,vector<int>&dp,int i,int k) {
  if(i == 0) return 0;
  if(i < 0) return -1e9;
  
  if(dp[i] != -1) return dp[i];
  
  int ans = INT_MAX;
  for(int j = 1;j <= k;j++) {
    int call = check(nums,dp,i-j,k);
    if(i - j >= 0 && call != -1e9) {
      ans = min(ans,abs(nums[i] - nums[i-j]) + call);
    }
  }
  return dp[i] = ans;
} 



int main() {
  int n,k;
  cin >> n >> k;
  vector<int>nums(n);
  for(int i = 0;i < n;i++) {
    cin >> nums[i];
  }
//   vector<int>dp(n,-1);
//   int ans = check(nums,dp,n-1,k);
//   cout << ans << endl; 



  return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  cin >> n >> k;
  vector<int>nums(n);
  for(int i = 0;i < n;i++) {
    cin >> nums[i];
  }
  
  vector<int>dp(n,INT_MAX);
  dp[0] = 0;
  for(int i = 1;i < n;i++) {
    for(int j = 1;j <= k;j++) {
      int call_index = i - j;
      if(call_index < 0) break;
      dp[i] = min(dp[i],abs(nums[i] - nums[call_index]) + dp[call_index]);
    }
  }
  cout << dp[n-1] << endl; 
  return 0;
}