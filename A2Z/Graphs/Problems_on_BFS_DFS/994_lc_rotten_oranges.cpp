class Solution {
public:
    bool isValid(int x,int y,int n,int m) {
        if(x < 0 || y < 0 || x >= n || y >= m) return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>>q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j,0});
                } 
            }
        }
        int time = 0;
        while(!q.empty()) {
            int x = q.front()[0]; int y = q.front()[1]; time = q.front()[2];
            visited[x][y] = 1;
            q.pop();
            if(isValid(x+1,y,n,m) && visited[x+1][y] == 0 && grid[x+1][y] == 1) {
                visited[x+1][y] = 1;
                q.push({x+1,y,time+1});
            }
            if(isValid(x-1,y,n,m) && visited[x-1][y] == 0 && grid[x-1][y] == 1) {
                visited[x-1][y] = 1;
                q.push({x-1,y,time+1});
            }
            if(isValid(x,y+1,n,m) && visited[x][y+1] == 0 && grid[x][y+1] == 1) {
                visited[x][y+1] = 1;
                q.push({x,y+1,time+1});
            }
            if(isValid(x,y-1,n,m) && visited[x][y-1] == 0 && grid[x][y-1] == 1) {
                visited[x][y-1] = 1;
                q.push({x,y-1,time+1});
            }
        }

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(visited[i][j] == 0 && grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};