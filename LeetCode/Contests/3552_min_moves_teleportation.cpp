// // class Solution {
// // public:

// //     unordered_map<char,vector<pair<int,int>>>umap;
// //     int m,n;
// //     vector<string>matrix;

// //     bool isValid(int i, int j) {
// //         if(i < 0 || j < 0 || i >= m || j >= n) return false;
// //         return true;
// //     }

// //     int check(int i,int j,int mask,vector<vector<int>>visited) {
// //         if(i == m - 1 && j == n - 1) {
// //             if(matrix[i][j] == '#') return 1e9;
// //             return 0;
// //         }

// //         visited[i][j] = 1;
// //         int ans = 1e9;

// //         if(matrix[i][j] != '.') {
// //             int ch = matrix[i][j] - 'A';
// //             if((mask & (1 << ch)) > 0) {
// //                 for(auto it : umap[matrix[i][j]]) {
// //                     int newMask = mask & (~(1 << ch));
// //                     if(!visited[it.first][it.second]) {
// //                         ans = min(ans, check(it.first, it.second, newMask, visited));
// //                     }
// //                 }
// //             }
// //         }

// //         vector<int>x_coord = {-1,0,1,0}; 
// //         vector<int>y_coord = {0,1,0,-1};
        
// //         for(int k = 0;k < 4;k++) {
// //             int newX = i + x_coord[k]; int newY = j + y_coord[k];
// //             if(isValid(newX,newY) && matrix[newX][newY] != '#') {
// //                 ans = min(ans,1 + check(newX,newY,mask,visited));
// //             }
// //         }
// //         visited[i][j] = 0;
// //         return ans;
// //     }
    
// //     int minMoves(vector<string>& mat) {
// //         matrix = mat;
// //         m = mat.size();
// //         n = mat[0].size();
// //         for(int i = 0;i < m;i++) {
// //             for(int j = 0;j < n;j++) {
// //                 if(mat[i][j] != '.' && mat[i][j] != '#') {
// //                     umap[mat[i][j]].push_back({i,j});
// //                 }
// //             }
// //         }
// //         vector<vector<int>>visited(m,vector<int>(n,0));
// //         return check(0,0,(1 << 26) - 1,visited);
// //     }
// // };

//MLE
// class Solution {
// public:
//     unordered_map<char, vector<pair<int, int>>> umap;
//     int m, n;
//     vector<string> matrix;

//     vector<vector<vector<int>>>dp;

//     bool isValid(int i, int j) {
//         return i >= 0 && j >= 0 && i < m && j < n;
//     }

//     int check(int i, int j, int mask, vector<vector<int>>& visited) {
//         if (i == m - 1 && j == n - 1) {
//             return matrix[i][j] == '#' ? 1e9 : 0;
//         }

//         if(dp[i][j][mask] != -1) return dp[i][j][mask];

//         visited[i][j] = 1;
//         int ans = 1e9;

//         // Teleportation
//         if (matrix[i][j] != '.' && matrix[i][j] != '#') {
//             char ch = matrix[i][j];
//             int bit = ch - 'A';
//             if ((mask & (1 << bit)) > 0) {
//                 int newMask = mask & (~(1 << bit));  // disable teleportation for this char
//                 for (auto& it : umap[ch]) {
//                     if (!visited[it.first][it.second]) {
//                         ans = min(ans, check(it.first, it.second, newMask, visited));
//                     }
//                 }
//             }
//         }

//         // Move in 4 directions
//         vector<int> x_coord = {-1, 0, 1, 0};
//         vector<int> y_coord = {0, 1, 0, -1};

//         for (int k = 0; k < 4; k++) {
//             int newX = i + x_coord[k];
//             int newY = j + y_coord[k];
//             if (isValid(newX, newY) && matrix[newX][newY] != '#' && !visited[newX][newY]) {
//                 ans = min(ans, 1 + check(newX, newY, mask, visited));
//             }
//         }

//         visited[i][j] = 0;  // backtrack
//         return dp[i][j][mask] = ans;
//     }

//     int minMoves(vector<string>& mat) {
//         matrix = mat;
//         m = mat.size();
//         n = mat[0].size();

//         if (mat[0][0] == '#' || mat[m - 1][n - 1] == '#') return -1;

//         // Populate teleport map
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (mat[i][j] != '.' && mat[i][j] != '#') {
//                     umap[mat[i][j]].emplace_back(i, j);
//                 }
//             }
//         }

//         vector<vector<int>> visited(m, vector<int>(n, 0));
//         dp = vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>((1<<26),-1)));
//         int result = check(0, 0, (1 << 26) - 1, visited);
//         return result >= 1e9 ? -1 : result;
//     }
// };


class Solution {
public:

    int minMoves(vector<string>& matrix) {
        vector<vector<pair<int,int>>>v(26);
        int m = matrix.size(); int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]!='.' && matrix[i][j]!='#') 
                {
                    v[matrix[i][j]-'A'].push_back({i,j});
                }
            }
        }

        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        vis[0][0]=1;
        if(matrix[0][0]=='.') q.push({{0,0},0});        
        else 
        {
            int idx=matrix[0][0]-'A';
            for(auto j:v[idx])
            {
                vis[j.first][j.second]=1;
                q.push({{j},0});
            }
        }

        vector<vector<int>> dir={{0,-1},{-1,0},{1,0},{0,1}};
        while(!q.empty())
        {
            int i=q.front().first.first,j=q.front().first.second,cost=q.front().second;
            q.pop();
            if(i==m-1 and j==n-1) return cost;
            for(int k=0;k<4;k++)
            {
                int ni=i+dir[k][0],nj=j+dir[k][1];
                if(ni>=0 and ni<m && nj>=0 && nj<n && !vis[ni][nj] && matrix[ni][nj]!='#')
                {
                    vis[ni][nj]=1;
                    if(matrix[ni][nj]=='.') q.push({{ni,nj},cost+1});
                    else
                    {
                        int idx=matrix[ni][nj]-'A';
                        for(auto j:v[idx])
                        {
                            q.push({{j},cost+1});
                            vis[j.first][j.second]=1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
