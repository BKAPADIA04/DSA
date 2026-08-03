#define ll long long
class Solution {
public:

    vector<ll>preSum;

    void printV() {
        for(auto it : preSum) cout << it << " ";
        cout << endl;
    }
    
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        ll n = tasks.size(); ll m = shifts.size();
        vector<int>answer;
        preSum = vector<ll>(n+1);
        for(ll i = 1;i <= n;i++) {
            preSum[i] = preSum[i-1] + tasks[i-1];
        }
        // printV();
        ll total = preSum[n];
        ll curr = 0ll;
        for(ll i = 0;i < m;i++) {
            ll currTime = min((ll)shifts[i], total - curr);
            curr += currTime;

            if(curr == total) {
                answer.push_back(0);
                curr = 0;
            }
            else {
                int idx = upper_bound(preSum.begin(), preSum.end(), curr) - preSum.begin() - 1;
                answer.push_back(n - idx);
            }
        }
        return answer;
    }
};
