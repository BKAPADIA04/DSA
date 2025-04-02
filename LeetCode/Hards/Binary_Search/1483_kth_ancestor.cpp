class TreeAncestor {
public:

    vector<vector<int>>up;
    vector<int>depth;
    int log;

    TreeAncestor(int n, vector<int>& parent) {
        log = 0;
        while((1 << log) <= n) {
            log++;
        }
        up = vector<vector<int>>(n,vector<int>(log));
        depth = vector<int>(n);
        parent[0] = 0;

        // ith node -> 2 ^ j th ancestor
        for(int v = 0;v < n;v++) {
            up[v][0] = parent[v];
            if(v != 0) depth[v] = depth[parent[v]] + 1;

            for(int j = 1;j < log;j++) {
                up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) return -1;
        for(int j = log - 1;j >= 0;j--) {
            if(k & (1 << j)) {
                node = up[node][j];
                k -= (1 << j);
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
