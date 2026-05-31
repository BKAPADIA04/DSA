class Solution {
public:

    vector<int>nums;
    int n;
    vector<vector<int>>items;
    int dp[1001][1501][2];

    int check(int i, int budget, int done) {
        if(budget <= 0) return 0;
        if(i == n) return 0;

        if(dp[i][budget][done] != -1) return dp[i][budget][done];

        int dontBuy = check(i+1, budget,0);
        int buy = 0;
        if(items[i][1] <= budget) {
            if(done == 0) {
                buy = nums[i] + check(i, budget - items[i][1],1);
            }
            else {
                buy = 1 + check(i, budget - items[i][1],1);
            }
        }

        return dp[i][budget][done] = max(buy, dontBuy);
    }
    
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        nums = vector<int>(n,1);
        this->items = items;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i == j) continue;

                if((items[j][0] % items[i][0]) == 0) nums[i]++;
            }
        }

        // for(auto it : nums) cout << it << " ";
        memset(dp, -1, sizeof(dp));
        return check(0,budget,0);
    }
};
