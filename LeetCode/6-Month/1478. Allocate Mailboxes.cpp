class Solution {
public:

    vector<vector<int>>preCost;
    int dp[102][102][102];
    vector<int>houses;
    int n;

    int check(int i, int j, int k) {
        if(k == 1) return preCost[i][j];

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int ans = INT_MAX;
        for(int p = i;p < j;p++) {
            int temp = check(p+1, j, k - 1);
            if(temp != INT_MAX) {
                ans = min(ans, preCost[i][p] + temp);
            }
        }

        return dp[i][j][k] = ans;
    }

    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        n = houses.size();
        this->houses = houses;
        preCost = vector<vector<int>>(n,vector<int>(n,0));
        
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                int cost = 0;
                int mid = (i + j)/2;
                for(int k = i;k <= j;k++) {
                    cost += abs(houses[k] - houses[mid]);
                }

                preCost[i][j] = cost;
            }
        }
        memset(dp, -1, sizeof(dp));
        return check(0, n - 1, k);
    }
};
