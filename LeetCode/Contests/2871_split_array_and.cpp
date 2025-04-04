class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n = nums.size();
        int and_ = nums[0];
        for(int i = 1;i < n;i++) {
            and_ = and_ & nums[i];
        }
        if(and_ != 0) return 1;
        int curr = 0; and_ = -1;
        for(int i = 0;i < n;i++) {
            if(and_ == -1) and_ = nums[i]; 
            else and_ = and_ & nums[i];
            if(and_ == 0) { curr++; and_ = -1;}
        }
        return curr;
    }
};
