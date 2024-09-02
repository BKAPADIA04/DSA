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

// or

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of paths from the top-left corner (0, 0) to the bottom-right corner (n-1, m-1)
int mazeObstacles(int n, int m, vector<vector<int>> &maze) {
    vector<int> prev(m, 0); // Initialize a vector to store the previous row's path counts

    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++) {
            // Base conditions
            if (i > 0 && j > 0 && maze[i][j] == -1) {
                temp[j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                continue;
            }
            if (i == 0 && j == 0) {
                temp[j] = 1; // If we are at the starting point, there is one path to it
                continue;
            }

            int up = 0;
            int left = 0;

            // Check if we can move up and left (if not at the edge of the maze)
            if (i > 0)
                up = prev[j]; // Number of paths from above (previous row)
            if (j > 0)
                left = temp[j - 1]; // Number of paths from the left (current row)

            // Total number of paths to reach (i, j) is the sum of paths from above and left
            temp[j] = up + left;
        }
        prev = temp; // Update the previous row with the current row
    }

    // The final result is stored in prev[m-1], which represents the destination in the last row
    return prev[m - 1];
}

int main() {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    int n = maze.size();
    int m = maze[0].size();

    cout << "Number of paths with obstacles: " << mazeObstacles(n, m, maze) << endl;
    return 0;
}

