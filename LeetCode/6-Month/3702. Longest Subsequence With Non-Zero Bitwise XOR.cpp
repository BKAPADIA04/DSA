class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int bitXor = 0;
        int zeroes = 0;
        for(int i = 0;i < n;i++) {
            if(nums[i] == 0) zeroes++;
            bitXor ^= nums[i];
        }
        if(bitXor) return n;
        if(bitXor == 0) {
            if(zeroes == n) return 0;
        }
        return n - 1;
    }
};
