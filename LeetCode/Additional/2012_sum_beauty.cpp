class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int>sufMin(n,INT_MAX); sufMin[n - 1] = nums[n - 1];
        for(int i = n - 2;i >= 0;i--) {
            sufMin[i] = min(sufMin[i + 1],nums[i]);
        }

        int preMax = nums[0];
        int answer = 0;
        for(int i = 1;i < n - 1;i++) {
            if(nums[i] > preMax && nums[i] < sufMin[i+1]) {
                answer += 2;
            }
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1]) {
                answer += 1;
            }
            preMax = max(preMax,nums[i]);
        }
        return answer;
    }
};
