class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1;i < n;i++) {
            if(nums[i] == nums[i-1]) {
                nums[i-1] *= 2;
                nums[i] = 0;
            }
        }
        int i = 0; int j = 0;
        while(i < n) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                i++; j++;
            }
            else {
                i++;
            }
        }
        for(;j < n;j++) nums[j] = 0;
        
        return nums;
    }
};
