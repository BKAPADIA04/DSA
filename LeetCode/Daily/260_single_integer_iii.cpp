class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long xorr = 0;
        for(int i = 0;i < n;i++) xorr ^= nums[i];

        int num1 = 0; int num2 = 0;
        long long lastSetBitNum = xorr & -xorr;
        
        for(long long i : nums) {
            if(lastSetBitNum & i) num1 ^= i;
        }

        num2 = xorr ^ num1;

        return {num1,num2};
    }
};
