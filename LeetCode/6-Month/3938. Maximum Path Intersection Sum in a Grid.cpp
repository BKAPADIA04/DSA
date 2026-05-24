class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = INT_MIN;
        int curr = INT_MIN;

        for(int i = 0;i < m;i++) {
            curr = grid[i][0];
            for(int j = 1;j < n;j++) {
                int tmpSum = curr + grid[i][j];
                ans = max(ans, tmpSum);

                if(i > 0 && i < m - 1 && j > 0 && j < n - 1) ans = max(ans, grid[i][j]);

                curr = max(grid[i][j], curr + grid[i][j]);
            }
        }

        for(int j = 0;j < n;j++) {
            curr = grid[0][j];
            for(int i = 1;i < m;i++) {
                int tmpSum = curr + grid[i][j];
                ans = max(ans, tmpSum);

                if(i > 0 && i < m - 1 && j > 0 && j < n - 1) ans = max(ans, grid[i][j]);

                curr = max(grid[i][j], curr + grid[i][j]);
            }
        }

        return ans;
    }
};
