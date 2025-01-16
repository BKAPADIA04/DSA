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
    
    void unionbySize(vector<int>&par,vector<int>&size,int X,int Y) {
        int ult_x = find(par,X);
        int ult_y = find(par,Y);
        if(ult_x == ult_y) return;
        
        if(size[ult_x] < size[ult_y]) {
            par[ult_x] = ult_y;
            size[ult_y] += size[ult_x];
        }
        else {
            par[ult_y] = ult_x;
            size[ult_x] += size[ult_y];
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int rowMax = -1;
        int colMax = -1;
        for(int i = 0;i < stones.size();i++) {
            rowMax = max(rowMax,stones[i][0]);
            colMax = max(colMax,stones[i][1]);
        }
        int n = rowMax + colMax + 1;
        vector<int>par(n+1); vector<int>size(n+1,1);
        for(int i = 0;i <= n;i++) par[i] = i;

        map<int,int>visited;
        for(int i = 0;i < stones.size();i++) {
            int row = stones[i][0];
            int col = stones[i][1] + rowMax + 1;
            unionbySize(par,size,row,col);
            visited[row] = 1;
            visited[col] = 1;
        }

        int numConnected = 0;
        for(auto it:visited) {
            if(find(par,it.first) == it.first) numConnected++;
        }
        print(par);
        cout << numConnected << endl;
        return stones.size() - numConnected;
    }
};