class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int ans = 0;
        int count = 0;
        for(int i = 0;i < n;i++) {
            if(nums[i] == maxi) {
                count++;
            }
            else {
                count = 0;
            }
            ans = max(ans,count);

        }
        return ans;
    }
};
