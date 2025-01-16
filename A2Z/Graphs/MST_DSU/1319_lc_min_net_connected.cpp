class Solution {
public:

    void print(vector<int>v) {
        for(auto it:v) cout << it << " ";
        cout << endl;
    }

    int find(vector<int>&par,int X) {
        if(par[X] == X) return X;
        else return par[X] = find(par,par[X]);
    }
    
    void unionbyRank(vector<int>&par,vector<int>&rank,int X,int Y) {
        int ult_x = find(par,X);
        int ult_y = find(par,Y);
        if(ult_x == ult_y) return;
        
        if(rank[ult_x] < rank[ult_y]) par[ult_x] = ult_y;
        else if(rank[ult_y] < rank[ult_x]) par[ult_y] = ult_x;
        else {
            par[ult_y] = ult_x;
            rank[ult_x]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < (n - 1)) return -1;
        vector<int>par(n,0); vector<int>rank(n,0);
        for(int i = 0;i < n;i++) {
            par[i] = i;
        }

        int count = 0;
        for(int i = 0;i < connections.size();i++) {
            if(find(par,connections[i][0]) == find(par,connections[i][1])) {
                count++; continue;
            }
            unionbyRank(par,rank,connections[i][0],connections[i][1]);
        }
        int components = 0;
        for(int i = 0;i < n;i++) {
            if(par[i] == i) components++;
        }
        if(count >= components - 1) return components - 1;
        return -1;
    }
};