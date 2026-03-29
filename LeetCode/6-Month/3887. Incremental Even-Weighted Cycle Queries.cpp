class Solution {
public:

    int n;
    vector<int>parent;
    vector<int>preXor;
    int answer;

    int findParent(int x) {
        if(parent[x] == x) return x;

        int par = parent[x];
        int y = findParent(par);
        preXor[x] ^= preXor[par];
        return parent[x] = y;
    }

    void unite(int x, int y, int wt) {
        int ultX = findParent(x);
        int ultY = findParent(y);

        if(ultX != ultY) {
            answer++;
            parent[ultX] = ultY;
            preXor[ultX] = preXor[x] ^ preXor[y] ^ wt;
        }
        else {
            if((preXor[x] ^ preXor[y]) == wt) answer++;
        }
    }

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        this->n = n;
        parent = vector<int>(n,0);
        preXor = vector<int>(n,0);

        for(int i = 0;i < n;i++) parent[i] = i;

        answer = 0;

        for(int i = 0;i < (int)edges.size();i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            int wt = edges[i][2];

            unite(x,y,wt);
        }

        return answer;
    }
};
