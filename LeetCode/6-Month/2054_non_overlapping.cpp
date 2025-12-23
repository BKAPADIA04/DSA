class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = events.size();
        sort(events.begin(),events.end());
        int maxVal = 0; int maxSum = 0;

        for(int i = 0;i < n;i++) {
            int startTime = events[i][0];
            int endTime = events[i][1];
            int val = events[i][2];

            while(!pq.empty() && pq.top().first < startTime) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            maxSum = max(maxSum, val + maxVal);
            pq.push({endTime,val});
        }
        return maxSum;
    }
};
