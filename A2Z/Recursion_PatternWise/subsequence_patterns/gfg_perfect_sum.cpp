#include <bits/stdc++.h>
using namespace std;

int perfectSum(int arr[], int n, int sum)
{
    int mod = 1e9 + 7; 
    vector<vector<int> >dp(n,vector<int>(sum+1,0));
    // Base Case : sum = 0 => empty subset
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    if (arr[0] <= sum) {
        dp[0][arr[0]] = 1;
    }
    // if (arr[0] == 0) dp[0][0] = 2; 

    for(int i = 1;i < n;i++) {
        for(int j = 1;j <= sum;j++) {
            int notTaken = dp[i-1][j] % mod;
            int taken = 0;
            if(arr[i] <= j) {
                taken = dp[i-1][j - arr[i]] % mod;
            }
            dp[i][j] = (notTaken + taken) % mod;
        }
    }
    return dp[n-1][sum] % mod;
}

int main() {
    int arr[] = {9 ,7 ,0 ,3 ,9 ,8 ,6 ,5 ,7 ,6};
    int n = 10;
    cout << perfectSum(arr,n,31) << endl;
}