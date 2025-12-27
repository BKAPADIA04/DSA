#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll>totalSum(n+1);
        vector<ll>preSum(n+1);
        for(int i = 1;i <= n;i++) {
            preSum[i] = preSum[i-1] + prices[i-1];
            totalSum[i] = totalSum[i-1] + (ll)((ll)prices[i-1] * (ll)strategy[i-1]);
        }

        ll answer = totalSum[n];
        // cout << answer << endl;

        for(ll i = 1;i <= n - k + 1;i++) {
            ll removeSum = totalSum[i+k-1] - totalSum[i-1];
            ll addSum = preSum[i+k-1] - preSum[i+k/2-1];
            ll possi = totalSum[n] - removeSum + addSum;
            answer = max(answer, possi);
        }
        return answer;
    }
};
