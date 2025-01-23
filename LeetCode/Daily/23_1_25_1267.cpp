class Solution {
public:

    int bfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int i,int j) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 1;
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j] = 1;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i < m;i++) {
                if(visited[i][y] == 0 && grid[i][y] == 1) {
                    count++;
                    q.push({i,y});
                    visited[i][y] = 1;
                }
            }
            for(int i = 0;i < n;i++) {
                if(visited[x][i] == 0 && grid[x][i] == 1) {
                    count++;
                    q.push({x,i});
                    visited[x][i] = 1;
                }
            }
        }

        return count;
    }


    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        
        int answer = 0; 
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(visited[i][j] == 0 && grid[i][j] == 1) {
                    int temp = bfs(grid,visited,i,j);
                    if(temp > 1) answer += temp;
                }
            }
        }
    return answer;
    }
};

/*class DSU{
    vector<int> parent;
    vector<int> size;
    public:
        DSU(int cap){
            parent.resize(cap, 0);
            size.resize(cap, 1);
            for(int i=0;i<cap;i++){
                parent[i] = i;
            }
        }
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]);
    }
    bool unionBySize(int a , int b){
        a = findParent(a);
        b = findParent(b);
        if(a==b) return false;
        if(size[b]>size[a]) swap(a,b);
        parent[b] = a;
        size[a]+=size[b];
        return true;
    }
    int sizeEqualToTwo(){
        int cnt = 0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i and size[i]==2){
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowHash(n);
        vector<int> colHash(m);
        DSU dsu(n+m);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                    dsu.unionBySize(i, n+j);
                }
            }
        }
        cout << dsu.sizeEqualToTwo() << "\n";
        ans-=dsu.sizeEqualToTwo();
        return ans;
    }
};*/
