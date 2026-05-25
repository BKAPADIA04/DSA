class Solution {
public:

    bool isIncrease(vector<int>&nums, int minIdx) {
        int n = nums.size();
        int i;
        for(i = minIdx;i < minIdx + n;i++) {
            if(nums[(i + 1) % n] - 1 != nums[i % n]) break;
        }

        if((i + 1) % n == minIdx) return true;
        return false;
    }
    
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0;
        for(int i = 1;i < n;i++) {
            if(nums[i] < nums[minIdx]) minIdx = i;
        }
        bool isIncreasing = isIncrease(nums, minIdx);
        bool isDecreasing = false;
        if(!isIncreasing) {
            reverse(nums.begin(), nums.end());
            minIdx = n - 1 - minIdx;
            isDecreasing = isIncrease(nums, minIdx);
        }

        if(!isIncreasing && !isDecreasing) return -1;

        int ans = n;
        if(isIncreasing) {
            ans = min(minIdx, 2 + n - minIdx);
        }
        else {
            ans = min(1 + minIdx, 1 + n - minIdx);
        }
        
        return ans;
    }
};
