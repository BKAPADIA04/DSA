class Solution {
public:


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // cycle detection
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i = 0;i < prerequisites.size();i++) {
            indegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int>q;
        for(int i = 0;i < numCourses;i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int temp = numCourses;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            temp--;
            for(int ch:adj[top]) {
                indegree[ch]--;
                if(indegree[ch] == 0) q.push(ch);
            }
        }
        return temp == 0;
    }
};