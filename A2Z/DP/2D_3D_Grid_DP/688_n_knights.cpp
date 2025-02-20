class Solution {
public:
    bool isValid(int m,int n,int x,int y) {
        if(x < 0 || y < 0 || x>= m || y >= n) return false;
        return true;
    }

    double check(vector<vector<vector<double>>>&dp,int x,int y,int k,int m,int n) {
        if(k <= 0) {
            if(isValid(m,n,x,y)) return 1.0;
            return 0.0;
        }

        if(dp[x][y][k] != -1.0) return dp[x][y][k];

        vector<int>x_coord = {-2,-1,1,2,2,1,-1,-2};
        vector<int>y_coord = {-1,-2,-2,-1,1,2,2,1};

        double ans = 0.0;
        for(int i = 0;i < 8;i++) {
            int x_new = x + x_coord[i];
            int y_new = y + y_coord[i];

            if(isValid(m,n,x_new,y_new) && k > 0) {
                ans += 0.125 * check(dp,x_new,y_new,k-1,m,n);
            }
        }
        return dp[x][y][k] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
       vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1.0)));
       return check(dp,row,column,k,n,n);
    }
};
