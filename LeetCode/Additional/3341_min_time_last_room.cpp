class Solution {
public:

    bool isValid(int n,int m,int x,int y) {
        if(x < 0 || y < 0 || x >= n || y >= m) return false;
        return true;
    }

    int minTimeToReach(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        dist[0][0] = 0;
        while(!pq.empty()) {
            int time = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            if(x == (n - 1) && y == (m - 1)) return time;

            vector<int>x_coord = {-1,0,1,0}; 
            vector<int>y_coord = {0,1,0,-1};

            for(int i = 0;i < 4;i++) {
                int x_temp = x + x_coord[i];
                int y_temp = y + y_coord[i];

                if(isValid(n,m,x_temp,y_temp)) {
                    int temp_time = max(time + 1, nums[x_temp][y_temp] + 1); 
                    if(temp_time < dist[x_temp][y_temp]) {
                        dist[x_temp][y_temp] = temp_time;
                        pq.push({temp_time,x_temp,y_temp});
                    }
                }
            }
        }
        return -1;
    }
};
