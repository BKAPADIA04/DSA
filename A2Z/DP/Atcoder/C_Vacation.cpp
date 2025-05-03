#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int> >&dp) {
  for(auto it: dp) {
    for(auto el: it) {
      cout << el << " ";
    }
    cout << endl;;
  }
  cout << endl;
}

int check(vector<vector<int> >&nums,vector<vector<int> >&dp,int prev,int i) {
  if(i < 0) return INT_MIN;
  
  if(dp[i][prev] != -1) return dp[i][prev];
  
  int ans = INT_MIN;
  for(int j = 0;j < 3;j++) {
    if(prev == j) continue;
    int temp = check(nums,dp,j,i-1);
    
    int opt = nums[i][j];
    if(temp != INT_MIN) {
      opt += temp;
    }
    ans = max(ans,opt);
  }
  
  return dp[i][prev] = ans;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int> >nums(n,vector<int>(3,0));
  for(int i = 0;i < n;i++) {
    int ele1,ele2,ele3; cin >> ele1 >> ele2 >> ele3;
    nums[i][0] = ele1; nums[i][1] = ele2; nums[i][2] = ele3;
  }
  // int answer = INT_MIN;
  // for(int i = 0;i < 3;i++) {
  //   vector<vector<int> >dp(n,vector<int>(3,-1));
  //   answer = max(answer,check(nums,dp,i,n-1));
  //   // print(dp);
  // }
  // cout << answer << endl;
  
  vector<vector<int> >dp(n,vector<int>(3,INT_MIN));
  for(int i = 0;i < 3;i++) dp[0][i] = nums[0][i];

  

  for(int i = 1;i < n;i++) {
    for(int prev = 0;prev < 3;prev++) {
      for(int j = 0;j < 3;j++) {
        if(prev == j) continue;
        int temp = dp[i-1][prev];
        int opt = nums[i][j];
        if(temp != INT_MIN) {
          opt += temp;
        }
        dp[i][j] = max(dp[i][j],opt);
      }
    }
  }
  
  cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << endl;
}