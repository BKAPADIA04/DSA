class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i < n;i++) {
            if(nums[i] == 0 && (n - i < 3)) return -1;
            else if(nums[i] == 0) {
                ans++;
                for(int j = i;j < i + 3 && j < n;j++) {
                    nums[j] ^= 1;
                }
            }
        }
        return ans;
    }
};
