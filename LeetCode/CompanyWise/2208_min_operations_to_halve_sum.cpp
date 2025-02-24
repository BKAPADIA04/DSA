#define ll long long
class Solution {
public:
    int halveArray(vector<int>& nums) {
        ll n = nums.size();
        priority_queue<double>pq; double sum = 0.0;
        for(ll i = 0;i < n;i++) { sum += nums[i] * 1.0; pq.push((double)nums[i]); }
        // double sum = accumulate(nums.begin(),nums.end(),0.0);

        double req = sum/2.0;
        ll count = 1;
        while(!pq.empty()) {
            double num = pq.top();
            pq.pop();
            req -= (num/2.0);
            if(req <= 0) return count;
            pq.push(num/2.0);
            count++;
        }

        return count;
    }
};
