
#define ll long long
class Solution {
public:

    vector<bool>visited;

    bool dfs(vector<vector<int>>&adj,int &count, int node, int parent) {
        visited[node] = true;
        count += 1;
        for(int x : adj[node]) {
            if(!visited[x]) {
                if(dfs(adj,count,x,node)) return true;
            }
            else if(x != parent) return true;
        }
        return false;
    }

    long long maxScore(int n, vector<vector<int>>& edges) {
        int val = n;
        vector<vector<int>> G(n + 1);
        for (auto &it : edges) {
            G[it[0]].push_back(it[1]);
            G[it[1]].push_back(it[0]); 
        }

        visited = vector<bool>(n + 1, false);

        vector<pair<int, int>> c, nc; // cyclic and noncyclic -> {size, startnode}

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int cnt = 0;
                if (dfs(G, cnt, i, -1)) {
                    c.push_back({cnt, i});
                } else {
                    nc.push_back({cnt, i});
                }
            }
        }

        sort(c.rbegin(), c.rend());
        sort(nc.rbegin(), nc.rend());

        ll anss = 0;
        visited = vector<bool>(n + 1, false);
        val = n;

        // first priority cyclic component
        for (auto &i : c) {
            int s = i.first; // size
            vector<ll> a(s);
            int st = val - s + 1, e = val; 
            int j = 0;

            for( j = 0; j < s / 2; j++){
                a[j] = st++, a[s - j - 1] = st++;
            }

            if(s % 2)
                a[j] = st; 

            for(int i = 1; i < s; i++)
                anss += (a[i] * a[i - 1]);
            anss += a.back() * a.front(); // cycle thats why
            val = val - s;
        }
// Acyclic
        for (auto &i : nc) {
            int s = i.first;
            vector<ll> a(s);
            int st = val - s + 1, e = val;

            int j = 0;
            for( j = 0; j < s / 2; j++){
                a[j] = st++, a[s - j - 1] = st++;
            }
            if(s % 2)
                a[j] = st;

            cout << endl; 
// theree is no cycle
            for(int i = 1; i < s; i++)
                anss += (a[i] * a[i - 1]);

            val = val - s;
        } 
        return anss;
    }
};
