class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        vector<int>answer;
        int left = 0; int right = 0;
        int consecutiveCount = 1;
        while(right < n) {
            if(right - left + 1 < k) {
                if(right > 0 && nums[right] == (nums[right - 1] + 1)) consecutiveCount++;
                else consecutiveCount = 1;
                right++;
            }
            else {
                if(right > 0 && nums[right] == (nums[right - 1] + 1)) consecutiveCount++;
                else consecutiveCount = 1;
                if(consecutiveCount >= k) answer.push_back(nums[right]);
                else answer.push_back(-1);
                left++;
                right++;
            }
        }
        return answer;
    }
};
