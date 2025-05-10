class Solution {
public:

    int n;
    unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int>>>>dp;

    int check(vector<vector<int>>&grid, int r1, int c1, int r2,int c2) {
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;

        if(r1 == (n - 1) && c1 == (n - 1)) return grid[r1][c1]; // player 1 and player 2 both at same position which is (n - 1,n - 1)

        if(dp.find(r1) != dp.end() && dp[r1].find(c1) != dp[r1].end() && dp[r1][c1].find(r2) != dp[r1][c1].end() && dp[r1][c1][r2].find(c2) != dp[r1][c1][r2].end()) return dp[r1][c1][r2][c2];

        int currCherry = 0;
        if(r1 == r2 && c1 == c2) currCherry = grid[r1][c1];
        else currCherry = grid[r1][c1] + grid[r2][c2];

        int nextCherry = INT_MIN;
        
        // right , right
        nextCherry = max(nextCherry, check(grid,r1,c1+1,r2,c2+1));
        // right , down
        nextCherry = max(nextCherry, check(grid,r1,c1+1,r2+1,c2));
        // down , right
        nextCherry = max(nextCherry, check(grid,r1+1,c1,r2,c2+1));
        // down , down
        nextCherry = max(nextCherry, check(grid,r1+1,c1,r2+1,c2));

        if(nextCherry == INT_MIN) return dp[r1][c1][r2][c2] = INT_MIN;
        currCherry += nextCherry;
        return dp[r1][c1][r2][c2] = currCherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = check(grid,0,0,0,0);
        if(ans < 0) return 0;
        return ans;
    }
};
