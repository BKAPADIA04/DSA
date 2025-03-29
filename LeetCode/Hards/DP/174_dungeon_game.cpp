class Solution {
public:

    int n,m;

    int check(vector<vector<int>>& dungeon,vector<vector<int>>&dp,int i,int j) {
        if(i == n - 1 && j == m - 1) {
            if(dungeon[i][j] > 0) return 1;
            else return abs(dungeon[i][j]) + 1;
        }

        if(dp[i][j] != -1e5) return dp[i][j];

        int down = INT_MAX; int right = INT_MAX;
        if(i + 1 < n) {
            down = check(dungeon,dp,i+1,j);
        }
        if(j + 1 < m) {
            right = check(dungeon,dp,i,j+1);
        }

        return dp[i][j] = max(1,min(down,right) - dungeon[i][j]);
    }


    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1e5));
        return check(dungeon,dp,0,0);
    }
};
