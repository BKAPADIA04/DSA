class Solution {
public:

    vector<vector<vector<int>>>dp;

    int cost(int v) {
        return (v == 0 ? 0 : 1);
    }

    int check(vector<vector<int>>& grid, int m, int n, int i, int j, int k) {
        if (i >= m || j >= n) return INT_MIN;

        int c = cost(grid[i][j]);
        if (k < c) return INT_MIN;

        if(i == (m - 1) && j == (n - 1)) {
            return grid[i][j];
        }

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int addScore = grid[i][j]; int incurCost = cost(grid[i][j]);

        int right = 0; int down = 0;

        right = check(grid, m, n, i, j + 1, k - incurCost);
        down = check(grid, m, n, i + 1, j, k - incurCost);

        int best = max(right,down);
        if (best == INT_MIN) return dp[i][j][k] = INT_MIN;

        return dp[i][j][k] = best + addScore;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        dp = vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans = check(grid,m,n,0,0,k);
        if(ans == INT_MIN) return -1;
        return ans;
    }
};
