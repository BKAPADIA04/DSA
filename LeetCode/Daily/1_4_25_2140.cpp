#define ll long long
class Solution {
public:

    ll check(vector<vector<int>>&questions,vector<ll>&dp,ll index) {
        if(index >= questions.size()) return 0;

        if(dp[index] != -1) return dp[index]; 

        ll notTake = check(questions,dp,index + 1);
        ll points = questions[index][0];
        ll brainPower = questions[index][1];
        ll take = points + check(questions,dp,index + brainPower + 1);
        return dp[index] = max(notTake,take);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        ll n = questions.size();
        // vector<ll>dp(n + 1,-1);
        // return check(questions,dp,0);

        vector<ll>dp(n + 1,0);
        for(ll index = n - 1;index >= 0;index--) {
            ll notTake = dp[index + 1];
            ll take = 0;
            if(index + questions[index][1] + 1 < n) {
                take = questions[index][0] + dp[index + questions[index][1] + 1];
            }
            else {
                take = questions[index][0];
            }
            dp[index] = max(take,notTake);
        }
        // for(auto it:dp) cout << it << " ";
        return dp[0];
    }
};
