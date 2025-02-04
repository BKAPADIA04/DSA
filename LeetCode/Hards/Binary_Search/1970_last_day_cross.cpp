class Solution {
public:
    bool isValid(int m,int n,int x,int y) {
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    bool bfs(vector<vector<int>>&nums,vector<vector<int>>visited,queue<pair<int,int>>q) {
        int row = nums.size();
        int col = nums[0].size();
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == (row - 1)) return true; 

            vector<int>x_coord = {-1,0,1,0};
            vector<int>y_coord = {0,1,0,-1};

            for(int i = 0;i < 4;i++) {
                int temp_x = x + x_coord[i];
                int temp_y = y + y_coord[i];

                if(isValid(row,col,temp_x,temp_y) && visited[temp_x][temp_y] == 0 && nums[temp_x][temp_y] == 0) {
                    visited[temp_x][temp_y] = 1;
                    q.push({temp_x,temp_y});
                }
            }
        }
        return false;
    }

    void print(vector<vector<int>>v) {
        for(auto it:v) {
            for(auto it1:it) cout << it1 << " ";
            cout << endl;
        }
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0; int high = row * col; int ans = INT_MIN;
        vector<vector<int>>nums(row,vector<int>(col,0)); int new_mid = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(new_mid == -1) {
                new_mid = mid;
                for(int i = 0;i <= mid;i++) nums[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            else {
                if(new_mid > mid) {
                    for(int i = mid+1;i <= new_mid;i++) nums[cells[i][0]-1][cells[i][1]-1] = 0;
                }
                else {
                    for(int i = new_mid+1;i <= mid;i++) nums[cells[i][0]-1][cells[i][1]-1] = 1;
                }
                new_mid = mid;
            } 
            // for(int i = 0;i <= mid;i++) nums[cells[i][0]-1][cells[i][1]-1] = 1;

            // print(nums); cout << endl;

            queue<pair<int,int>>q;
            vector<vector<int>>visited(row,vector<int>(col,0));
            for(int i = 0;i < col;i++) {
                if(nums[0][i] == 0) {
                    visited[0][i] = 1;
                    q.push({0,i});
                }
            }

            bool answer = bfs(nums,visited,q);
            // cout << answer << endl;

            if(answer) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans + 1;
    }
};

/*class DSU:
    def __init__(self, N):
        self.p = list(range(N))

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        self.p[xr] = yr

class Solution:
    def latestDayToCross(self, n, m, C):
        row, col = len(C), len(C[0])
        dsu = DSU(m*n + 2)
        grid = [[1] * m for _ in range(n)]
        neibs = [[0,1],[0,-1],[1,0],[-1,0]]
        C = [(x-1, y-1) for x, y in C]

        def index(x, y):
            return x * m + y + 1

        for i in range(len(C) - 1, -1, -1):
            x, y = C[i][0], C[i][1]

            grid[x][y] = 0
            for dx, dy in neibs:
                ind = index(x+dx, y+dy)
                if x+dx>=0 and x+dx<n and y + dy >= 0 and y + dy < m and grid[x+dx][y+dy] == 0:
                    dsu.union(ind, index(x, y))
            if x == 0:
                dsu.union(0, index(x, y))
            if x == n - 1:
                dsu.union(m*n + 1, index(x, y))

            if dsu.find(0) == dsu.find(m*n + 1):
                return i
                */
