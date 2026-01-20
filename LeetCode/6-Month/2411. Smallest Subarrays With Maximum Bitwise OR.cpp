class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int>sufMask(32,-1);
        int n = nums.size();
        vector<int>answer(n,1);
        bool flag = false;
        for(int i = n - 1;i >= 0;i--) {
            int maxiIndex = -1;
            if(nums[i] != 0) flag = true;
            else if(nums[i] == 0) {
                if(i == n - 1 || !flag) answer[i] = 1;
                else if(flag) {
                    answer[i] = answer[i+1] + 1;
                }
                continue;
            }
            for(int j = 0;j < 32;j++) {
                if((1 << j) & nums[i]) sufMask[31 - j] = i;
                maxiIndex = max(maxiIndex, sufMask[31 - j]);
            }
            answer[i] = maxiIndex - i + 1;
        }

        return answer;
    }
};
