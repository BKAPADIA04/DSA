class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0;i < n;i++) {
            pq.push({intervals[i][1],intervals[i][0]});
        }

        int count = 0; int prev = INT_MIN;
        while(!pq.empty()) {
            int start = pq.top().second;
            int end = pq.top().first;
            pq.pop();

            if(prev == INT_MIN) {
                prev = end; continue;
            }
            
            if(start >= prev) {
                prev = end;
            }
            else {
                count++;
            }
        }
        return count;
    }
};
