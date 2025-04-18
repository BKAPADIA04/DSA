#define ll long long
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0;i < tasks.size();i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
        int i = 0;
        int n = tasks.size();
        ll time = 0;
        vector<int>answer;
        while(i < n || !pq.empty()) {
            if(pq.empty()) {
                time = max(time, (ll)tasks[i][0]);
            }

            while(i < n && time >= tasks[i][0]) {
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }

            int len = pq.top().first;
            int index = pq.top().second;
            time += len;
            answer.push_back(index);
            pq.pop();
        }
        
        return answer;
    }
};
