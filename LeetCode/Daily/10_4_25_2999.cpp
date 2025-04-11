#define ll long long
class Solution {
public:

    vector<ll>dp;

    ll check(int index,bool limitLow,bool limitHigh, string &low, string &high,int &preLen,int &limit, string &s) {
        if(index == low.size()) return 1;

        if(!limitLow && !limitHigh && dp[index] != -1) return dp[index];

        int lo = limitLow ? low[index] - '0' : 0;
        int hi = limitHigh ? high[index] - '0' : 9;

        ll res = 0;
        if(index < preLen) {
            for(int digit = lo; digit <= min(hi,limit);digit++) {
                res += check(index + 1, limitLow && digit == lo, limitHigh && digit == hi, low, high,preLen,limit,s);
            }
        }
        else {
            int x = s[index - preLen] - '0';
            if (lo <= x && x <= min(hi, limit)) {
                res = check(index + 1, limitLow && x == lo, limitHigh && x == hi,low, high, preLen,limit,s);
            }
        }

        if(!limitLow && !limitHigh) dp[index] = res;

        return res;
    }


    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
       string low = to_string(start);
       string high = to_string(finish);

       int n = high.size();
       low = string(n - low.size(),'0') + low;
       int preLen = n - s.size();

        dp = vector<ll>(n,-1);

        return check(0,true,true,low,high,preLen,limit,s);
    }
};
