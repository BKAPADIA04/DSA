class Solution {
public:

    void createGraph(int color, vector<vector<int>>& nums, vector<vector<int>>&adj, vector<int>&indegree) {
        int miniX = INT_MAX; int miniY = INT_MAX;
        int maxiX = INT_MIN; int maxiY = INT_MIN;
        bool flag = false;

        int m = nums.size();
        int n = nums[0].size();

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(nums[i][j] == color) {
                    flag = true;
                    miniX = min(miniX, i);
                    miniY = min(miniY, j);

                    maxiX = max(maxiX, i);
                    maxiY = max(maxiY, j);
                }
            }
        }

        if(!flag) return;


        for(int i = miniX;i <= maxiX;i++) {
            for(int j = miniY;j <= maxiY;j++) {
                if(nums[i][j] != color) {
                    adj[nums[i][j]].push_back(color);
                    indegree[color]++;
                }
            }
        }

    }

    bool isPrintable(vector<vector<int>>& nums) {
        
        vector<vector<int>>adj(61);
        vector<int>indegree(61);

        for(int i = 1;i <= 60;i++) {
            createGraph(i, nums, adj, indegree);
        }

        queue<int>q;
        for(int i = 1;i <= 60;i++) {
            if(indegree[i] == 0) q.push(i);
        }
        int cnt = 0;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            cnt++;

            for(auto it : adj[curr]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return cnt == 60;
    }
};
