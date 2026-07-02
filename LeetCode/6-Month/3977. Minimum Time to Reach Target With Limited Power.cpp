class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        int m=edges.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }

        vector<vector<long long>> minTime(n,vector<long long>(power+1,LLONG_MAX));
        minTime[source][power]=0;

        priority_queue<pair<long long,pair<long long,int>>,vector<pair<long long,pair<long long,int>>>, greater<pair<long long,pair<long long,int>>>> pq;
        pq.push({0,{power,source}});

        while(!pq.empty()){
            long long t=pq.top().first;
            long long p=pq.top().second.first;
            int u=pq.top().second.second;
            pq.pop();
            if(minTime[u][p]<t){
                continue;
            }
            for(auto a: adj[u]){
                int v=a.first;
                long long timeCost=a.second;
                if(p>=cost[u]){
                    if(minTime[v][p-cost[u]]>(long long)(t+timeCost)){
                        minTime[v][p-cost[u]]=(t+timeCost);
                        pq.push({(t+timeCost),{p-cost[u],v}});
                    }
                }
            }
        }

        long long minans=LLONG_MAX;
        long long pow=0;
        for(int i=0;i<=power;i++){
            if(minTime[target][i]<=minans){
                minans=minTime[target][i];
                pow=i;
            }
        }
        
        if(minans==LLONG_MAX){
            return {-1,-1};
        }
        return {minans,pow};
    }
};
