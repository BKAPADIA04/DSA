class Solution {
public:

    int m,n;
    vector<vector<int>>grid;
    vector<vector<vector<int>>>dp;
    // int dp[1001][1001][1024];
    
    bool isValid(int i, int j) {
        if(i >= m || j >= n) return false;
        return true;
    }

    int check(int i, int j, int mask) {
        if(i == (m-1) && j == (n-1)) return mask ^ grid[i][j];
        
        int newMask = mask ^ grid[i][j];

        if(dp[i][j][newMask] != -1) return dp[i][j][newMask];

        int right = INT_MAX; int down = INT_MAX;
        if(isValid(i, j+1)) {
            right = check(i, j + 1, newMask);
        }

        if(isValid(i+1,j)) {
            down = check(i + 1, j, newMask);
        }

        return dp[i][j][newMask] = min(right, down);
    }
    
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        this->grid = grid;
        dp = vector<vector<vector<int>>>(m,vector<vector<int>>(n,
                                                    vector<int>(1024,-1)));

        return check(0,0,0);
    }
};
