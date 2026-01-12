class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>answer;
        
        for(int i = 0;i < n;i++) {
            while(!answer.empty() && nums[i] < answer.back() && answer.size() + n - i > k) answer.pop_back();

            if(answer.size() < k) answer.push_back(nums[i]);
        }

        
        return answer;
    }
};
