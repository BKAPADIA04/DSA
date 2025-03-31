#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        ll n = weights.size();
        priority_queue<ll>maxHeap;
        priority_queue<ll,vector<ll>,greater<ll>>minHeap;
        for(int i = 0;i < n - 1;i++) {
            ll sum = weights[i] + weights[i + 1];
            maxHeap.push(sum); minHeap.push(sum);
        }
        if((ll)k >= n) return 0;
        ll ans = 0;
        while(!maxHeap.empty() && !minHeap.empty() && k - 1 > 0) {
            ans += (maxHeap.top() - minHeap.top());
            maxHeap.pop();
            minHeap.pop();
            k--;
        }
        return ans;
    }
};
