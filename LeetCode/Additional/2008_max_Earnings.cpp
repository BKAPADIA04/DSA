#define ll long long
class Solution {
public:

    vector<ll>startV,endV,tipV,indexV;
    vector<ll>dp;

    static bool comparator(const vector<int>&a, const vector<int>&b) {
        return a[0] < b[0];
    }

    ll check(ll index, vector<vector<int>>& rides) {
        if(index >= (ll)rides.size()) return 0ll;
        if(dp[index] != -1) return dp[index];
        ll opt1 = check(index + 1, rides);
        vector<int>target = {rides[index][1], 0,0};
        ll nextIndex = lower_bound(rides.begin() + index + 1, rides.end(), target) - rides.begin();
        ll opt2 = (ll)rides[index][1] - (ll)rides[index][0] + (ll)rides[index][2] + check(nextIndex, rides);

        return dp[index] = max(opt1,opt2);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end(),comparator);
        for(int i = 0;i < rides.size();i++) {
            startV.push_back(rides[i][0]);
            endV.push_back(rides[i][1]);
            tipV.push_back(rides[i][2]);
            indexV.push_back(i);
        }
        dp = vector<ll>(rides.size(),-1);
        return check(0,rides);
    }   
};
