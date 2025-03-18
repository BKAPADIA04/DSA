class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mods(k,0); mods[0] = 1;
        int answer = 0; int preSum = 0;
        for(int i = 0;i < n;i++) {
            preSum += (nums[i] % k);
            if(preSum < 0) preSum += k;
            preSum %= k;
            answer += mods[preSum];
            mods[preSum]++;
        }
        return answer;
    }
};
