class Solution {
public:
    int check(int i,int j,int m,int n,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[i][j] == 1) return 0;
        if(i == (m-1) && j == (n-1) && obstacleGrid[i][j] == 0) {
            return 1;
        }
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = 0 , right = 0;
        if(i+1 < m && obstacleGrid[i+1][j] != 1)    
            left = check(i+1,j,m,n,dp,obstacleGrid);
        if(j+1 < n && obstacleGrid[i][j+1] != 1)    
            right = check(i,j+1,m,n,dp,obstacleGrid);
        return dp[i][j] = left + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return check(0,0,m,n,dp,obstacleGrid);
    }
};