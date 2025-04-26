class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int>dq_min,dq_max;
        int left = 0; int answer = 1;
        for(int i = 0;i < n;i++) {

            while(!dq_min.empty() && nums[dq_min.back()] > nums[i]) dq_min.pop_back();
            dq_min.push_back(i);
            while(!dq_max.empty() && nums[dq_max.back()] < nums[i]) dq_max.pop_back();
            dq_max.push_back(i);
            
            while(nums[dq_max.front()] - nums[dq_min.front()] > limit) {
                if(dq_max.front() == left) dq_max.pop_front();
                if(dq_min.front() == left) dq_min.pop_front();
                left++;
            }

            answer = max(answer, i - left + 1);
            
        } 
        return answer;
    }
};
