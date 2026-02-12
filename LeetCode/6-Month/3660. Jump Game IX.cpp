class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>preMax(n), sufMin(n);
        vector<int>answer(n);

        for(int i = 0;i < n;i++) {
            preMax[i] = i > 0 ? max(preMax[i-1], nums[i]) : nums[i];
        }

        for(int i = n - 1;i >= 0;i--) {
            sufMin[i] = i < n - 1 ? min(sufMin[i+1], nums[i]) : nums[i];
        }

        answer[n-1] = preMax[n-1];
        for(int i = n - 2;i >= 0;i--) {
            answer[i] = preMax[i];
            if(preMax[i] > sufMin[i+1]) answer[i] = max(answer[i], answer[i+1]);
        }

        return answer;
    }
};
