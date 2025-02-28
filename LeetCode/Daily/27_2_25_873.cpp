// #define ll long long
// class Solution {
//     public:
// int lenLongestFibSubseq(vector<int>& nums) {
//     ll n = nums.size();
//     ll ans = 0;
//     vector<vector<ll>>dp(n,vector<ll>(n,2));
//     for(ll i = n - 1;i >= 0;i--) {
//         ll maxi = 0;
//         for(ll j = i + 1;j < n;j++) {
//             ll sum = nums[i] + nums[j];
//             auto it = lower_bound(nums.begin() + j,nums.end(),sum);
//             if(it == nums.end() || *it != sum) continue;

//             ll k = it - nums.begin();

//             dp[i][j] = 1 + dp[j][k];
//             maxi = max(maxi,dp[i][j]);
//         }
//         if (maxi >= 3)
//             ans = max(ans, maxi);
//     }
//     return ans;
// }
// };

class Solution {
    int n;
    unordered_map<int,int>mp;
    vector<vector<int>>dp;
    int check(vector<int>&arr,int index,int prevIndex){


        if(index>=n){
            return 0;
        }

        if(dp[index][prevIndex]!=-1){
            return dp[index][prevIndex];
        }

        int take=0;
        if(mp.find(arr[index]+arr[prevIndex])!=mp.end()){
            take=1+check(arr,mp[arr[index]+arr[prevIndex]],index);   
        }

        return dp[index][prevIndex]=take;

    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        n=arr.size();
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int result=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x=check(arr,j,i);
                if(x){
                    result=max(result,2+x);
                }
            }
        }
        return result;
    }
};
