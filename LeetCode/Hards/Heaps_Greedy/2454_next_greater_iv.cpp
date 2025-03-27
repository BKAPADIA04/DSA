class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int>st;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        int n = nums.size();
        vector<int>answer(n,-1);
        for(int i = 0;i < n;i++) {

            while(!minHeap.empty() && minHeap.top().first < nums[i]) {
                answer[minHeap.top().second] = nums[i];
                minHeap.pop();
            }

            while(!st.empty() && nums[st.top()] < nums[i]) {
                minHeap.push({nums[st.top()],st.top()});
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};
