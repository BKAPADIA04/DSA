class Solution {
public:

    bool isValid(int m,int n,int x,int y) {
        if(x >= m || y >= n || x < 0 || y < 0) return false;
        return true;
    }

    void print(vector<vector<int>>dist) {
        for(int i = 0;i < dist.size();i++) {
            for(int j = 0;j < dist[0].size();j++) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }


    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& dist,vector<vector<int>>& visited,int i,int j,int m,int n,int prev) {
        
        if(!isValid(m,n,i,j) || matrix[i][j] <= prev) {
            return 0;
        }

        if(visited[i][j]) return dist[i][j];

        visited[i][j] = 1;

        int count = 1;
        count = max(count,1 + dfs(matrix,dist,visited,i-1,j,m,n,matrix[i][j]));
        count = max(count,1 + dfs(matrix,dist,visited,i+1,j,m,n,matrix[i][j]));
        count = max(count,1 + dfs(matrix,dist,visited,i,j-1,m,n,matrix[i][j]));
        count = max(count,1 + dfs(matrix,dist,visited,i,j+1,m,n,matrix[i][j]));
        // cout << "count : "<< count << endl;
        return dist[i][j] = count;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>dist(m,vector<int>(n,0));vector<vector<int>>visited(m,vector<int>(n,0));
        // dist = -1 implies not visited
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(!visited[i][j]) {
                    dfs(matrix,dist,visited,i,j,m,n,-1);
                }
            }
        }

        print(dist);

        int maxi = -1;
        for(int i = 0;i < dist.size();i++) {
            for(int j = 0;j < dist[0].size();j++) {
                maxi = max(maxi,dist[i][j]);
            }
        }

        return maxi;


        // vector<vector<int>>visited(m,vector<int>(n,0)); vector<vector<int>>dist(m,vector<int>(n,1));
        // int maxi = 1;
        // queue<pair<int,int>>q;
        // q.push({0,0}); visited[0][0] = 1;

        // while(!q.empty()) {
        //     int x = q.front().first;
        //     int y = q.front().second;
        //     q.pop();

        //     vector<int>x_coord = {-1,0,1,0};
        //     vector<int>y_coord = {0,1,0,-1};

        //     for(int i = 0;i < 4;i++) {
        //         int temp_x = x + x_coord[i];
        //         int temp_y = y + y_coord[i];

        //         if(isValid(m,n,temp_x,temp_y)) {
        //             if(matrix[temp_x][temp_y] > matrix[x][y] && visited[temp_x][temp_y] == 0) {
        //                 dist[temp_x][temp_y] = dist[x][y] + 1;
        //                 maxi = max(maxi,dist[temp_x][temp_y]);
        //                 q.push({temp_x,temp_y});
        //                 visited[temp_x][temp_y] = 1;
        //             }
        //             else if(matrix[temp_x][temp_y] <= matrix[x][y] && visited[temp_x][temp_y] == 0) {
        //                 q.push({temp_x,temp_y});
        //                 visited[temp_x][temp_y] = 1;
        //             }
        //             else if(matrix[temp_x][temp_y] > matrix[x][y] && visited[temp_x][temp_y]) {
        //                 dist[x][y] += 1;
        //                 maxi = max(maxi,dist[x][y]);
        //             }
        //         }
        //         cout << "maxi: " << maxi << endl;
        //     }
        // }
        // print(dist);
        // return maxi;
    }
};