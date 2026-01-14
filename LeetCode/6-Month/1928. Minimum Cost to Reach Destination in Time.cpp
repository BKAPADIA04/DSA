class Solution {
public:

    vector<vector<vector<int>>>adj;
    int n;
    vector<int>cost,time;

    int check(int maxTime) {
        int src = 0; int dest = n - 1;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({cost[src], time[src], src});

        while(!pq.empty()) {
            int c = pq.top()[0];
            int t = pq.top()[1];
            int u = pq.top()[2];

            pq.pop();

            for(auto it : adj[u]) {
                int v = it[0];
                int ptime = it[1];
                int pCost = it[2];

                if(ptime + t > maxTime) continue;

                if(cost[v] > pCost + c) {
                    cost[v] = pCost + c;
                    time[v] = ptime + t; 

                    pq.push({cost[v],time[v],v});
                }
                else if(time[v] > ptime + t) {
                    time[v] = ptime + t; 
                    pq.push({pCost + c,time[v],v});
                }
            }
        }

        return cost[n-1];

    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        n = passingFees.size();
        adj = vector<vector<vector<int>>>(n);
        cost = vector<int>(n,INT_MAX);
        time = vector<int>(n,INT_MAX);
        time[0] = 0;
        cost[0] = passingFees[0];
        for(int i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2],passingFees[edges[i][1]]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2],passingFees[edges[i][0]]});
        }
        int answer = check(maxTime);
        
        if(answer == INT_MAX) return -1;
        return cost[n-1];
    }
};
