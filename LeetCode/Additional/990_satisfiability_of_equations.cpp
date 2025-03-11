class Solution {
public:

    int find(vector<int>&parent,int X) {
        if(parent[X] == X) return X;
        return parent[X] = find(parent,parent[X]);
    }

    void unionByRank(vector<int>&parent,vector<int>&rank,int X,int Y) {
        int ult_x = find(parent,X);
        int ult_y = find(parent,Y);

        if(ult_x == ult_y) return;

        if(rank[ult_x] > rank[ult_y]) parent[ult_y] = ult_x;
        else if(rank[ult_y] > rank[ult_x]) parent[ult_x] = ult_y;
        else {
            parent[ult_x] = ult_y;
            rank[ult_y]++;
        }
    }


    bool equationsPossible(vector<string>& equations) {
        sort(equations.begin(),equations.end());
        for(auto it:equations) cout << it << " ";
        int n = equations.size();
        vector<int>parent(26,0); vector<int>rank(26,0);
        for(int i = 0;i < 26;i++) parent[i] = i;
        for(int i = 0;i < n;i++) {
            int char1 = equations[i][0] - 'a';
            int char2 = equations[i][3] - 'a';
            char ch = equations[i][1];

            if(ch == '!') {
                if(find(parent,char1) == find(parent,char2)) return false;
            }
            else {
                unionByRank(parent,rank,char1,char2);
            }
        }
        for(int i = 0;i < n;i++) {
            int char1 = equations[i][0] - 'a';
            int char2 = equations[i][3] - 'a';
            char ch = equations[i][1];
            if(ch == '!') {
                if(find(parent,char1) == find(parent,char2)) return false;
            }
            else {
                if(find(parent,char1) != find(parent,char2)) return false;
            }
        }
        return true;
    }
};
