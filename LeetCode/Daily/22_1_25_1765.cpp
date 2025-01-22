class Solution {
public:

    bool isValid(int m,int n,int i,int j) {
        if(i < 0 || j < 0 || i >= m | j >= n) return false;
        return true;
    }

    void bfs(vector<vector<int>>&answer,vector<vector<int>>visited,vector<vector<int>>&nums, queue<vector<int>>&q) {
        int m = nums.size();
        int n = nums[0].size();
        while(!q.empty()) {
            int dist = q.front()[0];
            int x = q.front()[1];
            int y = q.front()[2];

            q.pop();

            answer[x][y] = dist;

            vector<int>x_coord = {-1,0,1,0};
            vector<int>y_coord = {0,1,0,-1};

            for(int i = 0;i < 4;i++) {
                int x_new = x + x_coord[i]; int y_new = y + y_coord[i];
                if(isValid(m,n,x_new,y_new) && nums[x_new][y_new] == 0 && visited[x_new][y_new] == 0) {
                    visited[x_new][y_new] = 1;
                    q.push({dist+1,x_new,y_new});
                }
            }
        }
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& nums) {
        int m = nums.size(); int n = nums[0].size();
        vector<vector<int>>answer(m,vector<int>(n,INT_MAX));
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<vector<int>>q;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(nums[i][j] == 1) {
                    visited[i][j] = 1;
                    q.push({0,i,j});
                }
            }
        }
        bfs(answer,visited,nums,q);
        return answer;
    }
};
