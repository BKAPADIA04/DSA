#define p pair<int,int>
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i = 0;i < nums.size();i++) {
            pq.push({nums[i],i});
        }
        for(int i = 0;i < k;i++) {
            int ele = pq.top().first;
            int index = pq.top().second;

            int newele = ele * multiplier;
            pq.pop();

            pq.push({newele,index});
        }

        vector<int>answer(nums.size());
        while(!pq.empty()) {
            int ele = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            answer[index] = ele;
        }
        return answer;
    }
};