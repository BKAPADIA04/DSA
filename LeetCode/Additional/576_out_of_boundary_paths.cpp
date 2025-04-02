class Solution {
public:

    vector<vector<vector<int>>>dp;
    int mod = 1e9 + 7;

    bool isValid(int m, int n , int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    int check(int x, int y, int k, int m, int n) {
        if(!isValid(m,n,x,y)) return 1;
        if(k == 0) {
            if(!isValid(m,n,x,y)) return 1;
            else return 0;
        }
        if(dp[x][y][k] != -1) return dp[x][y][k];

        int left = check(x,y - 1,k - 1,m,n) % mod;
        int right = check(x, y + 1,k - 1,m,n) % mod;
        int up = check(x - 1,y,k - 1,m,n) % mod;
        int down = check(x + 1,y,k - 1,m,n) % mod;

        return dp[x][y][k] = ((left + right) % mod + (up + down) % mod) % mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(maxMove + 1,-1)));
        return check(startRow,startColumn,maxMove,m,n);
    }
};
