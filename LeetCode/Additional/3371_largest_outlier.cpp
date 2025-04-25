class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int i = 0;i < n;i++) {
            freq[nums[i]]++;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int answer = -1001;
        for(int i = 0;i < n;i++) {
            int tempSum = sum - nums[i];
            if(tempSum & 1) continue;
            tempSum /= 2;

            if(tempSum == nums[i]) {
                if(freq[tempSum] >= 2) {
                    if(nums[i] > answer) answer = nums[i];
                }
            }
            else {
                if(freq[tempSum] >= 1) {
                    if(nums[i] > answer) answer = nums[i];
                }
            }
        }
        return answer;
    }
};
