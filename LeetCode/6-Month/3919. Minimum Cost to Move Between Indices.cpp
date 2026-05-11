#define ll long long
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        ll n = nums.size();
        vector<ll>preSum(n), sufSum(n);

        for(ll i = 0;i < n - 1;i++) {
            if(i == 0 || (nums[i] - nums[i-1] > nums[i + 1] - nums[i])) {
                preSum[i+1] = preSum[i] + 1;
            }
            else {
                preSum[i+1] = preSum[i] + nums[i+1] - nums[i];
            }
        }

        for(ll i = n - 1;i > 0;i--) {
            if(i == n - 1 || (nums[i] - nums[i-1] <= nums[i + 1] - nums[i])) {
                sufSum[i-1] = sufSum[i] + 1;
            }
            else {
                sufSum[i-1] = sufSum[i] + nums[i] - nums[i-1];
            }
        }

        vector<int>answer;

        for(auto it : queries) {
            int l = it[0]; int r = it[1];
            if(l < r) answer.push_back(preSum[r] - preSum[l]);
            else answer.push_back(sufSum[r] - sufSum[l]);
        }

        return answer;
    }
};
