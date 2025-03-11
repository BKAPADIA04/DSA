class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>answer;
        for(int i = 0;i < n;i++) {
            if(nums[i] == 2) answer.push_back(-1);
            else {
                int j = 0;
                
                while(((1 << j) & nums[i]) > 0) {
                    j++;
                }
                
                j--;
                
                int ans = (1 << j) ^ nums[i];
                answer.push_back(ans);
            }
        }
        return answer;
    }
};
