class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0; int right = 1; int check = nums[0]; int maxi = 1;
        while(right < n) {
            while(left < right && (check & nums[right]) > 0) {
                check ^= nums[left++];
            }
            check = check | nums[right];
            maxi = max(maxi,right - left + 1);
            right++;
        }
        return maxi;
    }
};
