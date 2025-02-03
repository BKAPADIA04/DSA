#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int>nums(n);
    for(int i = 0;i < n;i++) {
        cin >> nums[i];
    }
    vector<int>dp(n+1,INT_MAX);
    dp[0] = dp[1] = 0;

    for(int i = 2;i <= n;i++) {
        int once = INT_MAX; int twice = INT_MAX;
        if(i - 2 >= 0) {
            once = dp[i-1] + abs(nums[i-1] - nums[i-2]);
        }
        if(i - 3 >= 0) {
            twice = dp[i-2] + abs(nums[i-1] - nums[i-3]);
        }
        dp[i] = min(once,twice);
    }
    cout << dp[n] << endl;
}


#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&dp) {
    for(int i = 0;i < dp.size();i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int check(vector<int>&nums,vector<int>&dp,int i) {
  if(i == 0) return 0;
  if(i < 0) return -1e9;
  if(dp[i] != -1) return dp[i];
  
  int once = INT_MAX; int twice = INT_MAX;
  int call1 = check(nums,dp,i-1);
  int call2 = check(nums,dp,i-2);
  if(i - 1 >= 0 && call1 != -1e9) {
    once = abs(nums[i] - nums[i-1]) + call1;
  }
  if(i - 2 >= 0 && call2 != -1e9) {
    twice = abs(nums[i] - nums[i-2]) + call2;
  }
  return dp[i] = min(once,twice);
}

int main() {
  int n; cin >> n;
    vector<int>nums(n);
    for(int i = 0;i < n;i++) {
        cin >> nums[i];
    }
    vector<int>dp(n,-1);
    int ans = check(nums,dp,n-1);
    // print(dp);
    cout << ans << endl;;
}