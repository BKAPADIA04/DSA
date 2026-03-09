#define ll long long
class Solution {
public:

    ll n;
    vector<ll>preSum;
    ll encCost; ll flatCost;

    ll check(ll left, ll right) {
        ll len = right - left + 1;

        ll answer = flatCost;
        ll ones = preSum[right+1] - preSum[left];
        if(ones > 0) answer = len * ones * encCost;

        if(len % 2 == 0) {
            ll mid = (left + right)/2;
            answer = min(answer, check(left, mid) + check(mid + 1, right));
        }

        return answer;
    }

    long long minCost(string s, int encCost, int flatCost) {
        n = s.size();
        preSum = vector<ll>(n+1,0);
        for(ll i = 1;i <= n;i++) {
            preSum[i] = preSum[i-1] + (s[i - 1] == '1' ? 1 : 0);
        }
        this->encCost = encCost;
        this->flatCost = flatCost;
        return check(0,n-1);
    }
};
