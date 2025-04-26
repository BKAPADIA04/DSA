#define ll long long
class Solution {
public:

    vector<ll>preSum;

    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        ll n = runningCosts.size();
        preSum = vector<ll>(n + 1,0);
        for(ll i = 1;i <= n;i++) {
            preSum[i] = preSum[i - 1] + runningCosts[i - 1];
        }

        deque<ll>dq;
        ll left = 0ll; ll answer = 0ll;
        for(ll right = 0ll; right < n; right++) {
            while(!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[right]) dq.pop_back();
            dq.push_back(right);

            ll k = right - left + 1;
            ll sum = preSum[right + 1] - preSum[left];
            ll maxi = chargeTimes[dq.front()];

            while(!dq.empty() && left < n && maxi + k * sum > budget) {
                if(dq.front() == left) dq.pop_front();
                left++;

                k = right - left + 1;
                sum = preSum[right + 1] - preSum[left];
                if(dq.empty()) break;
                maxi = chargeTimes[dq.front()];
            }
            if(!dq.empty()) answer = max(answer, k);
        }
        return answer;
    }
};
