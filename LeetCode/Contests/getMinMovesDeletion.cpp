#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int check(vector<int>&nums, int n,int i, int prev) {

    if(i == n || i == n - 1 || i == n - 2) {
        if(i == n) return nums[prev];
        if(i == n - 1) {
            return max(nums[i],nums[prev]);
        }
        if(i == n - 2) {
            return max({nums[n-1],nums[n-2],nums[prev]}) + min({nums[n-1],nums[n-2],nums[prev]});
        }
    }

    int ans = 0;

    if(prev == -1) {
        int a = nums[i];
        int b = nums[i + 1];
        int c = nums[i + 2];
        
        int temp1 = max(a,b) + check(nums,n,i+3,i+2);
        int temp2 = max(b,c) + check(nums,n,i+3,i);
        int temp3 = max(a,c) + check(nums,n,i+3,i+1);
        
        ans = min(temp1,min(temp2,temp3));
    } else {

        int a = nums[prev];
        int b = nums[i];
        int c = nums[i + 1];

        int temp1 = max(a,b) + check(nums,n,i+2,i+1);
        int temp2 = max(b,c) + check(nums,n,i+2,prev);
        int temp3 = max(a,c) + check(nums,n,i+2,i);
        
        ans = min(temp1,min(temp2,temp3));
    }

    return dp[i][prev+1] = ans;
}


int getMinMoves(vector<int>arr) {
    int n = arr.size();
    dp = vector<vector<int>>(n,vector<int>(n+1,-1));
    return check(arr,n,0,-1);
}

int main() {
    vector<int> arr1 = {3,1,4,2};
    vector<int> arr2 = {9, 8, 2,9, 5};
    cout << getMinMoves(arr1) << endl;
    cout << getMinMoves(arr2) << endl;
}
