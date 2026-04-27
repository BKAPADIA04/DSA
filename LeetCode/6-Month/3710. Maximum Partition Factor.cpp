#define ll long long
class Solution {
public:

    // bool isBipartite(vector<vector<int>>&adj) {
    //     int n = adj.size();
    //     vector<int>visited(n,0); vector<int>color(n,-1);
    //     queue<int>q;
    //     q.push({0,0}); color[0] = 0; visited[0] = 1;
    //     while(!q.empty()) {
    //         int node = q.front(); q.pop();
    //         for(auto it : adj[node]) {
    //             if(visited[it] && (color[it] == color[node])) return false;
    //             if(!visited[it]) {
    //                 color[it] = 1 - color[node];
    //                 q.push(it);
    //             }
    //         } 
    //     }
    //     return true;
    // }

    vector<int>parent;

    int findParent(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    bool unite(int x, int y) {
        int ultX = findParent(x);
        int ultY = findParent(y);

        if(ultX == ultY) return false;

        parent[ultX] = ultY;

        return true;
    }

    bool check(vector<vector<int>>& points, int mid, int n) {
        parent = vector<int>(2*n,0);
        for(int i = 0;i < 2*n;i++) parent[i] = i;

        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                int dist = (long long)abs(points[i][0] - points[j][0]) + (long long) abs(points[i][1] - points[j][1]);
                if(dist < mid) {
                    unite(i, j + n);
                    unite(j, i + n);
                }
            }
        }

        for(int i = 0;i < n;i++) {
            if(findParent(i) == findParent(i+n)) return false;
        }
        return true;


    }

    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 2) return 0;
        
        ll low = 0;
        ll high = INT_MAX;
        
        ll ans = 0;
        while(low <= high) {
            ll mid = low + (high - low)/2;
            if(check(points, mid, n)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;

    }
};
