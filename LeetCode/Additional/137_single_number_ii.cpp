class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n = nums.size(); int answer = 0;
        // for(int i = 0;i < 32;i++) {
        //     int sum = 0;
        //     for(int j = 0;j < n;j++) {
        //         if(nums[j] & (1 << i)) sum++;
        //     }
        //     if(sum % 3 != 0) answer |= (1 << i);
        // }
        // return answer;

        // Bucket Approach
        int ones = 0, twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos; // Remove from ones if it appears in twos  or add num to ones if num not it twos
            twos = (twos ^ num) & ~ones; // Remove from twos if it appears in ones
        }

        return ones; // The number appearing once remains in 'ones'
    }
};
