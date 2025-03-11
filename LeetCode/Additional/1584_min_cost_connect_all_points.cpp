class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i == j) continue;
                adj[i].push_back({j,abs(nums[i][0] - nums[j][0]) + abs(nums[i][1] - nums[j][1])});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int answer = 0;
        vector<int>visited(n,0);

        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node]) continue;

            answer += dist;
            visited[node] = 1;

            for(auto it:adj[node]) {
               pq.push({it.second,it.first});
            }
        }
        return answer;
    }
};
