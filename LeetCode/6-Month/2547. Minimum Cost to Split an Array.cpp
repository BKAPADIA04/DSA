#define ll long long
class Solution {
public:
    
    vector<vector<int>>trimmedLen;
    vector<ll>dp;

    ll check(vector<int>& nums, int k, int i, int n) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;
        for(int j = i;j < n;j++) {
            int trimmedCost = trimmedLen[i][j];
            int tempCost = k + trimmedCost;
            int next = check(nums, k, j + 1, n);
            if(next != INT_MAX) {
                tempCost += next;
                minCost = min(minCost, tempCost);
            }
        }

        return dp[i] = minCost;
    }

    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        trimmedLen = vector<vector<int>>(n,vector<int>(n,0));
        for(int i = 0;i < n;i++) {
            vector<int>mp(1001,0);
            int cnt = 0;
            for(int j = i;j < n;j++) {
                if(mp[nums[j]] > 0) {
                    if(mp[nums[j]] == 1) cnt += 2;
                    else cnt += 1;
                }
                mp[nums[j]]++;
                trimmedLen[i][j] = cnt;
            }
        }

        dp = vector<ll>(n,-1ll);

        return check(nums, k , 0, n);
    }
};
