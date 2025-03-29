#define ll long long
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0; int right = 0;
        ll sum = 0;
        int mini = n + 1;
        while(right < n) {
            sum += nums[right];
            while(sum >= target) {
                mini = min(mini, right - left + 1);
                sum -= nums[left]; left++;
            }
            right++;
        }
        return mini == (n + 1) ? 0 : mini;
    }
};
