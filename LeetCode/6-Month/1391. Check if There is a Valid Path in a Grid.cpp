class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int,int>>> dir(7);
        dir[1] = {{0,-1},{0,1}};   // left right
        dir[2] = {{-1,0},{1,0}};   // up down
        dir[3] = {{0,-1},{1,0}};   // left down
        dir[4] = {{0,1},{1,0}};    // right down
        dir[5] = {{0,-1},{-1,0}};  // left up
        dir[6] = {{0,1},{-1,0}};   // right up

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r==m-1 && c==n-1)
                return true;
            
            for(auto [dr,dc] : dir[grid[r][c]]){
                int nr = r + dr;
                int nc = c + dc;

                if(nr<0 || nc<0 || nr>=m || nc>=n || vis[nr][nc])
                    continue;

                // check reverse connection
                for(auto [bdr,bdc] : dir[grid[nr][nc]]){
                    if(nr + bdr == r && nc + bdc == c){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return false;
    }
};

/*class DSU
{
    public:
    vector<int> parent,size;
    DSU(int n)
    {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        size.resize(n,1);
    }
    int find(int x)
    {
        return parent[x] = (parent[x] == x ? x : find(parent[x]));
    }
    bool unite(int x, int y)
    {
        int a = find(x);
        int b = find(y);
        if(a == b)
            return false;
        if(size[a] < size[b])
            swap(a,b);
        size[a] += size[b];
        parent[b] = a;
        return true;
    }
};
class Solution {
public:
int N;
    int id(int i , int j)
    {
        return N*i + j;
    }
    bool hasValidPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        DSU dsu(m*n);
        N = n;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i)
                {
                    if((grid[i][j] == 2 || grid[i][j] == 5 || grid[i][j] == 6) && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4))
                        dsu.unite(id(i,j) , id(i-1,j));
                }
                if(j)
                {
                    if((grid[i][j] == 1 || grid[i][j] == 3 || grid[i][j] == 5) && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6))
                        dsu.unite(id(i,j) , id(i,j-1));
                }
            }
        }

        return dsu.find(id(0,0)) == dsu.find(id(m-1,n-1));
        
    }
};*/
