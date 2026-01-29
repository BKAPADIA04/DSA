#define ll long long
class Solution {
public:

    vector<vector<int>>dp;

    int check(int n, int k) {
        if(n <= 1) return n;

        if(k == 1) return n;

        if(dp[n][k] != -1) return dp[n][k];

        int ans = 1e9;
        int low = 1; int high = n;

        while(low <= high) {
            int mid = (low + high)/2;
            int eggBreak = check(mid - 1, k - 1);
            int notBreak = check(n - mid, k);

            if(eggBreak < notBreak) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }

            ans = min(ans, 1 + max(eggBreak, notBreak));
        }

        return dp[n][k] = ans;
    }

    int superEggDrop(int k, int n) {
        dp = vector<vector<int>>(n+1,vector<int>(k+1,-1));
        return check(n,k);
    }
};
