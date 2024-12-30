class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(int i = 0;i < n;i++) {
            for(auto it:graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        vector<int>answer(n,0);
        queue<int>q;
        for(int i = 0;i < n;i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int top = q.front(); q.pop();
            answer[top] = 1;
            for(auto it:adj[top]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        vector<int>ans;
        for(int i = 0;i < answer.size();i++) {
            if(answer[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};