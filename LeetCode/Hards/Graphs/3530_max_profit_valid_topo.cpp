#define ll long long
class Solution {
public:

    vector<int>visited, dp, indegree;
    vector<vector<int>>adj;

    int check(int state, int counter, int n, vector<int>&score) {
        if(state == (1 << n) - 1) return 0;
        // or
        if(counter > n) return 0;

        if(dp[state] != -1) return dp[state];

        int answer = 0;
        for(int i = 0;i < n;i++) {
            if(indegree[i] == 0 && !visited[i]) {
                visited[i] = 1;
                for(auto it : adj[i]) {
                    indegree[it]--;
                }

                int newState = state | (1 << i);
                answer = max(answer, counter * score[i] + check(newState, counter + 1, n, score));

                visited[i] = 0;
                for(auto it : adj[i]) {
                    indegree[it]++;
                }
            }
        }
        return dp[state] = answer;
    }


    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        visited.resize(n,0);
        dp.resize(1 << n, -1);
        indegree.resize(n,0);
        adj = vector<vector<int>>(n);
        for(int i = 0;i < edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        return check(0, 1, n, score);
    }
};
