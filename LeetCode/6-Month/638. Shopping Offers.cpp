class Solution {
public:
    int n;
    vector<int> price;
    vector<vector<int>> special;
    map<vector<int>, int> dp;

    int dfs(vector<int>& needs) {
        if (dp.count(needs)) return dp[needs];

        // Cost without any offer
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += needs[i] * price[i];

        // Try each special offer
        for (auto& offer : special) {
            vector<int> newNeeds = needs;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (offer[i] > newNeeds[i]) {
                    valid = false;
                    break;
                }
                newNeeds[i] -= offer[i];
            }

            if (valid)
                ans = min(ans, offer[n] + dfs(newNeeds));
        }

        return dp[needs] = ans;
    }

    int shoppingOffers(vector<int>& price_, vector<vector<int>>& special_, vector<int>& needs) {
        price = price_;
        special = special_;
        n = price.size();
        return dfs(needs);
    }
};
