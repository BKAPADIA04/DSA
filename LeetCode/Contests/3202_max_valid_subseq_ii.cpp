// class Solution {
// public:

//     vector<int>nums;
//     int n;
//     vector<vector<int>>dp;
//     vector<int>freq;
    
//     int maximumLength(vector<int>& arr, int k) {
//         nums = arr;
//         n = nums.size();
//         dp = vector<vector<int>>(n,vector<int>(k,1));
//         freq = vector<int>(k,-1);

//         freq[nums[n - 1] % k] = n - 1;

//         for(int i = n - 2;i >= 0;i--) {
//             for(int j = 0;j < k;j++) {
//                 int temp = (j - ((nums[i] % k) + k) % k) % k;
//                 if(temp < 0) temp += k;
//                 if(freq[temp] != -1) {
//                     int index = freq[temp];
//                     cout << index << " " << temp << " " << dp[index][temp] << endl;
//                     dp[i][j] = max(dp[i][j], 1 + dp[index][temp]);
//                 }
//                 // cout << i << " " << j << " " << dp[i][j] << endl;
//             }
//             freq[nums[i] % k] = i;
//         }

//         int maxi = 0;
//         for(auto it : dp) {
//             for(auto it1 : it) {
//                 // cout << it1 << " ";
//                 maxi = max(maxi,it1);
//             }
//             // cout << endl;
//         }

//         return maxi;
//     }
// };


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
    //      int n = nums.size();
    //       vector<vector<int>>dp(n, vector<int>(k, 0)); 
    //       int ans = 0;
    //       for (int i = 0; i < n; ++i) {
    //           for (int j = 0; j < i; ++j) {
    //             int mod = (nums[i] + nums[j]) % k;
    //             dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
    //             ans = max(ans , dp[i][mod]);
    //         }
    //     }
    //    return ans+1;

        int n = nums.size();
        int ans = 0;
        for(int mod = 0;mod < k;mod++) {
            vector<int>dp(k,0);
            for(int i = 0;i < n;i++) {
                int currSum = nums[i] % k;
                int prevSum = (mod - currSum + k) % k;
                dp[currSum] = max(dp[currSum], 1 + dp[prevSum]);
                ans = max(ans,dp[currSum]);
            }
        }
        return ans;
    }
};
