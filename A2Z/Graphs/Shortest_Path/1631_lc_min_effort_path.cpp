class Solution {
public:

    bool isValid(int x,int y,int m,int n) {
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        pq.push({0,0,0});
        dist[0][0] = 0;
        while(!pq.empty()) {
            int distance = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            
            if(x == (m-1) && y == (n-1)) return distance;

            vector<int>x_coord = {-1,0,1,0};
            vector<int>y_coord = {0,1,0,-1};

            for(int i = 0;i < 4;i++) {
                int temp_x = x + x_coord[i];
                int temp_y = y + y_coord[i];
                if(isValid(temp_x,temp_y,m,n)) {
                    int check = max(abs(heights[x][y] - heights[temp_x][temp_y]),distance);
                    if(check < dist[temp_x][temp_y]) {
                        pq.push({check,temp_x,temp_y});
                        dist[temp_x][temp_y] = check;
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};