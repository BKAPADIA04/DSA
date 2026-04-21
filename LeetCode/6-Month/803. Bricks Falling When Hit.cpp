class Solution {
public:
    vector<vector<int>> grid;
    int n, m;

    // DFS to mark stable bricks and count connected bricks
    int dfs(int i, int j) {
        grid[i][j] = 2;   // mark as stable
        int count = 0;

        if (i + 1 < n && grid[i + 1][j] == 1)
            count += 1 + dfs(i + 1, j);
        if (i - 1 >= 0 && grid[i - 1][j] == 1)
            count += 1 + dfs(i - 1, j);
        if (j + 1 < m && grid[i][j + 1] == 1)
            count += 1 + dfs(i, j + 1);
        if (j - 1 >= 0 && grid[i][j - 1] == 1)
            count += 1 + dfs(i, j - 1);

        return count;
    }

    vector<int> hitBricks(vector<vector<int>>& g, vector<vector<int>>& hits) {
        grid = g;
        n = grid.size();
        m = grid[0].size();

        // Step 1: apply all hits
        for (auto& hit : hits) {
            grid[hit[0]][hit[1]]--;
        }

        // Step 2: mark all stable bricks connected to top
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                dfs(0, j);
            }
        }

        int l = hits.size();
        vector<int> ans(l, 0);

        // Step 3: process hits in reverse
        for (int i = l - 1; i >= 0; i--) {
            int x = hits[i][0];
            int y = hits[i][1];

            grid[x][y]++;   // restore brick

            // check if restored brick becomes stable
            if (grid[x][y] == 1 &&
                (x == 0 ||
                 (x > 0 && grid[x - 1][y] == 2) ||
                 (x < n - 1 && grid[x + 1][y] == 2) ||
                 (y > 0 && grid[x][y - 1] == 2) ||
                 (y < m - 1 && grid[x][y + 1] == 2))) {

                ans[i] = dfs(x, y);
            }
        }

        return ans;
    }
};
