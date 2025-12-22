class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        vector<int>preSum(n,0);
        preSum[0] = nums[0];
        int mod = 1e9 + 7;
        for(int i = 1;i < n;i++) {
            preSum[i] = (preSum[i-1] + nums[i]) % mod;
        }

        
        for(int left = 0; left < n;left++) {
            int leftSum = preSum[left] % mod;
            int lower = lower_bound(preSum.begin() + left + 1, preSum.end(), 2 * leftSum) - preSum.begin();

            int upper = upper_bound(preSum.begin()+left+1,preSum.begin()+n-1, leftSum + ((preSum[n-1]-preSum[left])/2)) - preSum.begin();

            answer+=(max(0,(upper-lower)))%mod;
            answer=answer%mod;
        }

        return answer % mod;
    }
};
