#define ll long long
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>preSum(n,0);
        preSum[0] = nums[0];
        unordered_map<ll,int>leftPartitions, rightPartitions;

        for(int i = 0;i < n - 1;i++) {
            rightPartitions[preSum[i]]++;
            preSum[i + 1] = preSum[i] + nums[i + 1];
        }

        int maxWays = 0;
        if(preSum[n - 1] % 2 == 0) maxWays = rightPartitions[preSum[n - 1] / 2];

        for(int i = 0;i < n;i++) {
            int diff = k - nums[i];
            if((preSum[n - 1] + diff) % 2 == 0) {
                int ways = leftPartitions[(preSum[n - 1] + diff)/2] + rightPartitions[(preSum[n - 1] - diff)/2];
                maxWays = max(maxWays,ways);
            }

            leftPartitions[preSum[i]]++;
            rightPartitions[preSum[i]]--;
        }
        return maxWays;
    }
};
