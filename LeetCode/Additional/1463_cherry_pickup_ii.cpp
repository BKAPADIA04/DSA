class Solution {
public:

    int rows,cols;
    unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;

    int check(vector<vector<int>>&grid, int r, int c1, int c2) {
        if(r >= rows || c1 < 0 || c2 < 0 || c1 >= cols || c2 >= cols) return INT_MIN;
        if(r == rows - 1) { // both reach bottom together
            if(c1 == c2) return grid[r][c1];
            return grid[r][c1] + grid[r][c2];
        }

        if(dp.find(r) != dp.end() && dp[r].find(c1) != dp[r].end() && dp[r][c1].find(c2) != dp[r][c1].end()) {
            return dp[r][c1][c2];
        }

        int currCherry = 0;
        if(c1 == c2) currCherry = grid[r][c1];
        else currCherry = grid[r][c1] + grid[r][c2];

        int nextCherry = INT_MIN;
  
        vector<int>xCoord = {1,1,1}; vector<int>yCoord = {-1,0,1};
        for(int i = 0;i < 3;i++) {
            int temp_r = r + xCoord[i];
            int temp_c1 = c1 + yCoord[i];
            for(int j = 0;j < 3;j++) {
                int temp_c2 = c2 + yCoord[j];
                nextCherry = max(nextCherry, check(grid,temp_r,temp_c1,temp_c2));
            }
        }

        if(nextCherry == INT_MIN) return dp[r][c1][c2] = INT_MIN;
        currCherry = currCherry + nextCherry; 
        return dp[r][c1][c2] = currCherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        return check(grid,0,0,cols-1);
    }
};
