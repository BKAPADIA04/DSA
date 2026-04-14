#define ll long long
class Solution {
public:

    ll m,n;
    vector<int>robot;
    vector<vector<int>> factory;
    vector<vector<ll>>dp;

    ll check(ll i, ll j) {
        if(i == m) return 0ll;
        if(j == n) return LLONG_MAX;
        
        if(dp[i][j] != -1ll) return dp[i][j]; 

        ll notTake = check(i, j + 1);
        ll cost = 0ll;
        ll take = LLONG_MAX;

        ll pos = factory[j][0];
        ll lim = factory[j][1];

        for(ll k = 0;k < lim && i + k < m;k++) {
            cost += abs(pos - robot[i+k]);
            ll temp = check(i+k+1, j+1);
            if(temp != LLONG_MAX) {
                take = min(take, cost + temp);
            }
        }

        return dp[i][j] = min(take, notTake);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        m = robot.size();
        n = factory.size();
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        this->robot = robot;
        this->factory = factory;

        dp = vector<vector<ll>>(m,vector<ll>(n,-1ll));
        return check(0,0);
    }
};
