class Solution {
public:

    int MOD = 1e9 + 7;
    vector<vector<vector<vector<int>>>>dp;

    int check(int n, int index, int prevCol1, int prevCol2, int prevCol3) {
        if(index == n) return 1;
        
        if(dp[index][prevCol1+1][prevCol2+1][prevCol3+1] != -1) return dp[index][prevCol1+1][prevCol2+1][prevCol3+1];

        int answer = 0;

        for(int i = 0;i <= 2;i++) {
            if(prevCol1 == i) continue;
            for(int j = 0;j <= 2;j++) {
                if(prevCol2 == j) continue;
                for(int k = 0;k <= 2;k++) {
                    if(prevCol3 == k) continue;
                    if(j == i) continue;
                    if(k == j) continue;
                    int temp = check(n, index + 1, i, j, k) % MOD;
                    answer = answer % MOD + temp % MOD;
                    answer = answer % MOD;
                }
            }
        }
        return dp[index][prevCol1+1][prevCol2+1][prevCol3+1] = answer % MOD;
    }

    int numOfWays(int n) {
        dp = vector<vector<vector<vector<int>>>>(n,vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,-1))));
        return check(n,0,-1,-1,-1) % MOD;
    }
};
