#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ll n = nums.size();
        ll answer = 0;
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(ll i = 0;i < n;i++) pq.push(nums[i]);

        while(!pq.empty()) {
            ll first = pq.top(); pq.pop();
            if(first >= k) return answer;
            ll second = pq.top(); pq.pop();
            pq.push(min(first,second) * 2 + max(first,second));
            answer++;
        }
        return answer;
    }
};
