class Solution {
public:

    int n;
    vector<int>c, t;
    vector<vector<int>>dp;
    int check(int index, int wallsLeft) {
        if(wallsLeft <= 0) return 0;
        if(index >= n) return 1e9;

        if(dp[index][wallsLeft] != -1) return dp[index][wallsLeft];
        int paid = INT_MAX; int free = INT_MAX;

        paid = c[index] + check(index + 1, wallsLeft - 1 - t[index]);
        free = 0 + check(index + 1, wallsLeft);

        return dp[index][wallsLeft] = min(free,paid);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        c = cost; 
        t = time;
        dp = vector<vector<int>>(n,vector<int>(n + 1,-1));
        return check(0,n);
    }
};
