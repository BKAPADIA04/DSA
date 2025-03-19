class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0; int count = 0;
        for(int i = 0;i < n;i++) {
            if(nums[i]) {
                if(count & 1) count++;
            }
            else {
                if(count % 2 == 0) count++;
            }
        }
        return count;
    }
};
