class Solution {
public:
    
    vector<int>x_coord,y_coord;
    int m,n;

    bool isValid(int m, int n, int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    void dfs(vector<vector<int>>&heights, vector<vector<int>>&visited, int i, int j) {
        visited[i][j] = 1;
        for(int k = 0;k < 4;k++) {
            int x_new = i + x_coord[k]; int y_new = j + y_coord[k];
            if(isValid(m,n,x_new,y_new) && !visited[x_new][y_new] && heights[i][j] <= heights[x_new][y_new]) dfs(heights, visited, x_new, y_new);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        x_coord = {-1,0,1,0}; y_coord = {0,1,0,-1};
        m = heights.size(); n = heights[0].size();

        vector<vector<int>>visited1(m,vector<int>(n,0));
        vector<vector<int>>visited2(m,vector<int>(n,0));


        for(int i = 0;i < m;i++) {
            if(!visited1[i][0]) dfs(heights, visited1, i, 0);
        }

        for(int i = 0;i < n;i++) {
            if(!visited1[0][i]) dfs(heights, visited1, 0, i);
        }

        for(int i = 0;i < m;i++) {
            if(!visited2[i][n - 1]) dfs(heights, visited2, i, n - 1);
        }

        for(int i = 0;i < n;i++) {
            if(!visited2[m - 1][i]) dfs(heights, visited2, m - 1, i);
        }

        vector<vector<int>>answer;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(visited1[i][j] && visited2[i][j]) answer.push_back({i,j});
            }
        }
        return answer;
    }
};
