#define ll long long

class Solution {
public:

    int M; int N;
    int mod = 1e9 + 7;
    unordered_map<int,unordered_map<int,unordered_map<ll,ll>>>umap;

    bool isValid(int m,int n,int x,int y) {
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    ll check(vector<vector<int>>&grid, int x, int y, ll prod) {
        if(x == (M - 1) && y == (N - 1)) {
            prod = (prod * grid[x][y]);
            if(prod < 0) return -1;
            return prod;
        }
        
        if(umap.count(x) && umap[x].count(y) && umap[x][y].count(prod)) return umap[x][y][prod];

        ll temp1 = LLONG_MIN; ll temp2 = LLONG_MIN;
        if(isValid(M,N,x + 1,y)) {
            ll p = prod * grid[x][y];
            temp1 = check(grid, x + 1,y,p);
        }

        if(isValid(M,N,x,y + 1)) {
            ll p = prod * grid[x][y];
            temp2 = check(grid,x,y + 1,p);
        }

        return umap[x][y][prod] = max(temp1,temp2);
    }


    int maxProductPath(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();

        return check(grid,0,0,1) % mod;
    }
};
