class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // O(nlogk)
        // int n = nums.size();
        // vector<int>answer;
        // multiset<int>s;
        // int left = 0; int right = 0;

        // while(right < n) {
        //     s.insert(nums[right]);
        //     if(right - left + 1 < k) right++;
        //     else if(right - left + 1 == k) {
        //         auto it = s.end(); it--;
        //         answer.push_back(*it);
        //         s.erase(s.find(nums[left]));
        //         left++; right++;
        //     }
        // }
        // return answer;


        // O(n)
        int n = nums.size();
        vector<int>answer;
        deque<int>dq;
        for(int i = 0;i < n;i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            dq.push_back(i);

            if(!dq.empty() && dq.front() == (i - k)) dq.pop_front();

            if(i >= (k-1)) answer.push_back(nums[dq.front()]);
        }
        return answer;
    }
};