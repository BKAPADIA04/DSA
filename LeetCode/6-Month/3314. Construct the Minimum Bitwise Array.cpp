class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            int res = -1 ;
            int d = 1;
            while(tmp & d) {
                res = tmp - d;
                d = d << 1;
            }
            nums[i] = res;
        }
        return nums;
    }
};
