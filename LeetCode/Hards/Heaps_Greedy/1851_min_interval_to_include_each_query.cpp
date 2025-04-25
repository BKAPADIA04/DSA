class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        vector<pair<int,int>>v;
        for(int i = 0;i < queries.size();i++) {
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());
        sort(intervals.begin(),intervals.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        vector<int>answer(v.size(), -1);
        int index = 0;
        for(int i = 0;i < v.size();i++) {
            int ele = v[i].first;
            while(index < n && intervals[index][0] <= ele) {
                int start = intervals[index][0]; int end = intervals[index][1];
                minHeap.push({end - start + 1, end});
                index++;
            }

            while(!minHeap.empty() && minHeap.top().second < ele) {
                minHeap.pop();
            }

            if(!minHeap.empty()) {
                answer[v[i].second] = minHeap.top().first;
            }
            // agar empty hua toh already -1 hai
        }

        return answer;
    }
};
