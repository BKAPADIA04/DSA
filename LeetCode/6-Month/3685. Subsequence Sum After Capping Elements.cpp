class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        vector<int>arr = nums;
        sort(arr.begin(),arr.end());
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(j-arr[i-1]>=0) dp[i][j] = (dp[i-1][j] | dp[i-1][j-arr[i-1]]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        vector<bool>ans(n,false);
        for(int i=0;i<n;i++){
            int val = i+1;
            int inx = lower_bound(arr.begin(),arr.end(),val)-arr.begin();
            int ct = n-inx;
            for(int j=0;j<=ct;j++){
                if(k-(j*val)>=0) ans[i] = (ans[i] | dp[inx][k-(j*val)]);
            }
        }
        return ans;
    }
};
