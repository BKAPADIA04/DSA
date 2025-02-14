//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int check(vector<int>&nums,vector<vector<int>>&dp,int i,int j) {
        int n = nums.size();
        
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k = i;k <= j - 1;k++) {
            int temp = nums[i-1] * nums[k] * nums[j] + check(nums,dp,i,k) + check(nums,dp,k+1,j);
            mini = min(mini,temp);
        }
        
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(vector<int> &nums) {
        // code here
        int n = nums.size();
        int i = 1; int j = n - 1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return check(nums,dp,i,j);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends