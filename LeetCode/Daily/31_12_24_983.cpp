class Solution {
public:

    int check(int index,vector<int>& days, vector<int>& costs,vector<int>&dp,vector<int>&pass) {
        if(index >= days.size()) return 0;

        if(dp[index] != -1) return dp[index];

        int minCost = INT_MAX;
        for(int i = 0; i < 3;i++) {
            int nextIndex = lower_bound(days.begin(),days.end(),days[index] + pass[i]) - days.begin();
            minCost = min(minCost,costs[i] + check(nextIndex,days,costs,dp,pass));
        }
        return dp[index] = minCost;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n,-1);
        vector<int>pass; pass.push_back(1);pass.push_back(7);pass.push_back(30);

        return check(0,days,costs,dp,pass);
    }
};
