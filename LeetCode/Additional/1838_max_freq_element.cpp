class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        long long currSum = 0ll;
        while(right < n) {
            currSum += nums[right];
            while((long long)(right - left + 1) * nums[right] - currSum > k) {
                currSum -= nums[left];
                left++;
            }
            ans = max(ans,right - left + 1);
            right++;
        }
        return ans;
    }
};
