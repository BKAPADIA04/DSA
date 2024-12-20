class Solution {
public:

    bool isValid(int x,int y,int n,int m) {
        if(x < 0 || y < 0 || x >= n || y >= m) return false;
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>>q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> answer(n,vector<int>(m,0));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j,0});
                    visited[i][j] = 1;
                } 
            }
        }
        
        while(!q.empty()) {
            int i = q.front()[0]; int j = q.front()[1]; int cell = q.front()[2];
            q.pop(); answer[i][j] = cell;
            if(isValid(i+1,j,n,m) && visited[i+1][j] == 0 && grid[i+1][j] == 1) {
                visited[i+1][j] = 1;
                q.push({i+1,j,cell+1});
            }
            if(isValid(i-1,j,n,m) && visited[i-1][j] == 0 && grid[i-1][j] == 1) {
                visited[i-1][j] = 1;
                q.push({i-1,j,cell+1});
            }
            if(isValid(i,j+1,n,m) && visited[i][j+1] == 0 && grid[i][j+1] == 1) {
                visited[i][j+1] = 1;
                q.push({i,j+1,cell+1});
            }
            if(isValid(i,j-1,n,m) && visited[i][j-1] == 0 && grid[i][j-1] == 1) {
                visited[i][j-1] = 1;
                q.push({i,j-1,cell+1});
            }
        }
        return answer;
    }
};