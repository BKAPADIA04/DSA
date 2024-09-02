#include <bits/stdc++.h>
using namespace std;

int check(vector<vector<int>>& arr, int n, vector<vector<int>>& dp,int days,int task) {
    if(days == 0) {
        int points = 0;
        for(int i = 0; i < 3;i++) {
            if(i != task) {
                points = max(points,arr[0][i]);
            }
        }
        return points;
    }
    if(dp[days][task] != -1) return dp[days][task];
    int maxi = 0;
    for(int i = 0;i < 3;i++) {
        if(i != task) {
            int points = arr[days][i] + check(arr,n,dp,days-1,i);
            maxi = max(maxi,points);
        }   
    }
    return dp[days][task] = maxi;
}

int iterative_dp(vector<vector<int>>& arr, int n) {
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0] = max(dp[0][1],dp[0][2]);
    dp[0][1] = max(dp[0][0],dp[0][2]);
    dp[0][2] = max(dp[0][0],dp[0][1]);
    dp[0][3] = max(dp[0][0],max(dp[0][1],dp[0][2]));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < 4;j++) {
            dp[i][j] = 0;
            for(int k = 0;k < 3;k++) {
                if(k != j) {
                    int points = arr[i][k] + dp[i-1][k]; 
                    dp[i][j] = max(dp[i][j],points);
                }   
            }
        }
    }
    return dp[n-1][3];
}

int most_optimized(vector<vector<int>>& arr, int n) {
    vector<int>dp(4,0);
    dp[0] = max(dp[1],dp[2]);
    dp[1] = max(dp[0],dp[2]);
    dp[2] = max(dp[0],dp[1]);
    dp[3] = max(dp[0],max(dp[0],dp[2]));
    for(int i = 0;i < n;i++) {
        vector<int>temp(4,0);
        for(int j = 0;j < 4;j++) {
            temp[j] = 0;
            for(int k = 0;k < 3;k++) {
                if(k != j) {
                    int points = arr[i][k] + dp[k]; 
                    temp[j] = max(temp[j],points);
                }   
            }
        }
        dp = temp;
    }
    return dp[3];
}

int maximumPoints(vector<vector<int>>& arr, int n) {
    vector<vector<int>> dp(n,vector<int>(4,-1));
    // cout << check(arr,n,dp,n-1,3) << endl;
    cout << iterative_dp(arr,n) << endl;
}

int main() {
    vector<int> arr1 = {1,2,5};
    vector<int> arr2 = {3,1,1};
    vector<int> arr3 = {3,3,3};

    vector<vector<int>>arr;
    arr.push_back(arr1);
    arr.push_back(arr2);
    arr.push_back(arr3);
    maximumPoints(arr,3);
}