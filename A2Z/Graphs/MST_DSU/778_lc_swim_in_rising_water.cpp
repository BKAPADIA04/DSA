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

    bool isValid(int n,int x,int y) {
        return (x >= 0 && y >= 0 && x < n && y < n);
    }

    bool check(vector<vector<int>>& grid,vector<int>&par,vector<int>&size,int t) {
        int n = grid.size();
        int nodes = par.size();

        vector<int>x_coord = {-1,0,1,0};
        vector<int>y_coord = {0,1,0,-1};

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                int node = i + n * j;
                if(grid[i][j] > t) continue;
                for(int k = 0;k < 4;k++) {
                    int x_new = i + x_coord[k];
                    int y_new = j + y_coord[k];

                    int node_new = x_new + n * y_new;
                    if(isValid(n,x_new,y_new) && grid[x_new][y_new] <= t) {
                        if(find(par,node) == find(par,node_new)) continue;
                        else unionbySize(par,size,node,node_new);
                    }
                }
            }
        }
        // print(par);
        return (find(par,0) == find(par,nodes-1));
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int nodes = n * n - 1;
        vector<int>par(nodes+1);
        vector<int>size(nodes+1,1);
        for(int i = 0;i < par.size();i++) par[i] = i;
        // print(par);
        
        int low = 0; int high = par.size()-1;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(check(grid,par,size,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
            for(int i = 0;i < par.size();i++) { par[i] = i; size[i] = 1;}
        }
        return ans;
    } 
};

// Shortest Path
/*typedef pair<int,pair<int,int>>p;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size();
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<int>dirs = {-1,0,1,0,-1};
        int time = 0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        while(!pq.empty()){
            int currentTime = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            time = max(time, currentTime);
            if(row==n-1 && col==m-1)
                return time;
            for(int i=0;i<4;i++){
                int adjrow = row + dirs[i];
                int adjcol = col + dirs[i+1];
                if(adjrow>=0 && adjcol>=0 && adjrow<n && adjcol<m && !vis[adjrow][adjcol]){
                    pq.push({grid[adjrow][adjcol] , {adjrow, adjcol}});
                    vis[adjrow][adjcol] = true;
                } 
            }
        }
        return time;
    }
};*/