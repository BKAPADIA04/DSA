class Solution {
public:

    unordered_map<int,int> bfs(vector<int>&edges, int Node) {
        int n = edges.size();
        unordered_map<int,int>bfsVector;
        vector<int>visited(n,0);
        queue<pair<int,int>>q;
        q.push({Node,0});
        visited[Node] = 1;
        while(!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            bfsVector[node] = dist;
            q.pop();
            
            if(edges[node] != -1 && visited[edges[node]] == 0) {
                visited[node] = 1;
                q.push({edges[node], dist + 1});
            }
        }

        return bfsVector;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        unordered_map<int,int>bfs1 = bfs(edges, node1);
        unordered_map<int,int>bfs2 = bfs(edges, node2);
    
        int ans = INT_MAX; int index = -1;
        for(int i = 0;i < n;i++) {
            int d1 = INT_MAX; int d2 = INT_MAX;
            if(bfs1.find(i) != bfs1.end()) d1 = bfs1[i];
            if(bfs2.find(i) != bfs2.end()) d2 = bfs2[i];

            if(d1 == INT_MAX || d2 == INT_MAX) continue;
            if(max(d1,d2) < ans) {
                ans = max(d1,d2);
                index = i;
            }
        }

        return index;
    }
};
