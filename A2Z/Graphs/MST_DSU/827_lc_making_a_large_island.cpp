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
        if(x < 0 || y < 0 || x >= n || y >= n) return false;
        return true;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int nodes = n * n - 1; // last node
        vector<int>par(nodes+1);
        for(int i = 0;i < par.size();i++) par[i] = i;
        vector<int>size(nodes+1,1);

        vector<int>x_coord = {-1,0,1,0};
        vector<int>y_coord = {0,1,0,-1};

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                int node = i + n * j;
                if(grid[i][j] == 0) continue;
                for(int k = 0;k < 4;k++) {
                    int x_new = i + x_coord[k];
                    int y_new = j + y_coord[k];
                    int node_new = x_new + n * y_new;
                    if(isValid(n,x_new,y_new) && grid[x_new][y_new] == 1) {
                        if(find(par,node) == find(par,node_new)) continue;
                        else unionbySize(par,size,node,node_new); 
                    }
                }
            }
        }

        int maxi = *max_element(size.begin(),size.end());
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                int node = i + n * j;
                if(grid[i][j] == 1) continue;
                unordered_set<int>s;
                for(int k = 0;k < 4;k++) {
                    int x_new = i + x_coord[k];
                    int y_new = j + y_coord[k];
                    int node_new = x_new + n * y_new;
                    if(isValid(n,x_new,y_new) && grid[x_new][y_new] == 1) {
                        int og_par = find(par,node_new);
                        if(s.find(og_par) == s.end()) s.insert(og_par);
                    }
                }
                int temp = 0;
                for(auto it:s) {
                    temp += size[it];
                }
                maxi = max(maxi,temp+1);
            }
        }

        return maxi;
    }
};