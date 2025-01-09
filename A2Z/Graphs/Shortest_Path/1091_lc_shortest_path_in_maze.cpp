class Solution {
public:
    bool isValid(int x,int y,int n) {
        if(x < 0 || y < 0 || x >= n || y >= n) return false;
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        distance[0][0] = 1;
        if(grid[0][0] == 1) return -1;
        pq.push({1,0,0});

        while(!pq.empty()) {
            int dist = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];

            pq.pop();
            if(x == (n-1) && y == (n-1)) return dist;

            vector<int>x_corrd = {1,0,-1,0,1,1,-1,-1};
            vector<int>y_corrd = {0,1,0,-1,1,-1,1,-1};

            for(int i = 0;i < 8;i++) {
                int temp_x = x + x_corrd[i];
                int temp_y = y + y_corrd[i];
                if(isValid(temp_x,temp_y,n) && grid[temp_x][temp_y] == 0) {
                    if(1 + distance[x][y] < distance[temp_x][temp_y]) {
                        distance[temp_x][temp_y] = 1 + distance[x][y];
                        pq.push({distance[temp_x][temp_y],temp_x,temp_y});
                    }
                }
            }
        }
        if(distance[n-1][n-1] == INT_MAX) distance[n-1][n-1] = -1;
        return distance[n-1][n-1];
    }
};