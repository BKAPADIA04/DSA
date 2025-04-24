class Solution {
public:

    vector<int>preSum;

    vector<vector<vector<int>>>dp;

    int check(vector<int>&stones, int i, int j, int chance) {
        if(i >= j) return 0;
        if(dp[i][j][chance] != -1) return dp[i][j][chance];

        int ans = 0;

        if(chance == 1) {
            int temp1 = preSum[j + 1] - preSum[i + 1] + check(stones, i + 1, j,1 - chance);
            int temp2 = preSum[j] - preSum[i] + check(stones, i, j - 1,1 - chance);

            ans = max(temp1,temp2);
        }

        else {
            int temp1 = -(preSum[j + 1] - preSum[i + 1]) + check(stones, i + 1, j,1 - chance);
            int temp2 = -(preSum[j] - preSum[i]) + check(stones, i, j - 1,1 - chance);

            ans = min(temp1,temp2);
        }
        
        return dp[i][j][chance] = ans;
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        preSum.resize(n + 1, 0);
        for(int i = 1;i <= n;i++) {
            preSum[i] = preSum[i - 1] + stones[i - 1];
        }
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1,vector<int>(2,-1)));
        return check(stones, 0 , n - 1, 1);

    }
};

/*class Solution {
public:
    const int INF = INT_MAX;
    vector<vector<int>> memo;
    vector<int> preSum;
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        memo.assign(n, vector<int>(n, INF));
        preSum.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] + stones[i];
        return dp(0, n - 1);
    }
    int getSum(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
    int dp(int left, int right) {
        if (left == right) return 0; // only 1 stone, score = 0 -> difference = 0 as well
        if (memo[left][right] != INF) return memo[left][right];
        int scoreRemoveLeftMost = getSum(left + 1, right);
        int scoreRemoveRightMost = getSum(left, right - 1);
        int ans = max(scoreRemoveLeftMost - dp(left + 1, right), scoreRemoveRightMost - dp(left, right - 1));
        return memo[left][right] = ans;
    }
};*/
