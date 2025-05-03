#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<double> >&dp) {
  for(int i = 0;i < dp.size();i++) {
    for(int j = 0;j < dp[i].size();j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
}

double check(vector<double>&nums,vector<vector<double> >&dp,int index,int heads,int n) {
    // cout << index << " " << heads << endl;
   if(index < 0) {
    if(heads > (n/2)) return 1.0;
    return 0.0;
  }
  
  if(dp[index][heads] != -1) return dp[index][heads];
  
  double notTaken = (1 - nums[index]) * check(nums,dp,index-1,heads,n) * 1.0;
  double taken = 0.0;
  if(index >= 0) {
    taken = nums[index] * check(nums,dp,index-1,heads+1,n) * 1.0;
  }
  
  return dp[index][heads] = (notTaken + taken) * 1.0;
}


int main() {
  int n; cin >> n;
  vector<double>nums(n);
  for(int i = 0;i < n;i++) {
    double ele; cin >> ele; nums[i] = ele;
  }
  
//   vector<vector<double> >dp(n,vector<double>(n+1,-1));
//   double ans = check(nums,dp,n-1,0,n);
//     cout << setprecision(10) << ans << endl;


vector<vector<double> >dp(n+1,vector<double>(n+1,0));
  for(int j = 0;j < n + 1;j++) {
    if(j > (n/2)) dp[0][j] = 1.0;
  }
// print(dp);
for(int i = 1;i <= n;i++) {
  for(int j = n;j >= 0;j--) {
    double notTaken = (1 - nums[i-1]) * dp[i-1][j] * 1.0;
    double taken = 0.0;
    if(j + 1 <= n)
        taken = nums[i-1] * dp[i-1][j+1] * 1.0;
    
    dp[i][j] = (notTaken + taken) * 1.0;
  }
}
cout << setprecision(10) << dp[n][0] << endl;
//   print(dp);

// vector<vector<double> > dp(n+1, vector<double>(n+1, 0.0));

//     // Base case: If all coins are processed (index = -1), return 1.0 if heads > n/2, else 0.0
//     for (int j = 0; j <= n; j++) {
//         if (j > n/2) dp[0][j] = 1.0;  // Only valid when more heads than tails
//     }

//     // Fill DP table bottom-up
//     for (int i = 1; i <= n; i++) {  // Process each coin
//         for (int j = n; j >= 0; j--) {  // Process heads in reverse (like memoization)
//             double notTaken = (1 - nums[i-1]) * dp[i-1][j];  // Case where we don't take heads
//             double taken = (j < n) ? nums[i-1] * dp[i-1][j+1] : 0.0;  // Case where we take heads

//             dp[i][j] = notTaken + taken;  // Store result
//         }
//     }

//     cout << setprecision(10) <<  dp[n][0];
}