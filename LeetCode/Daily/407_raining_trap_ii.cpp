class Solution {
public:

    bool isValid(int x, int y, int m, int n) {
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<int>x_new = {-1,0,1,0};
        vector<int>y_new = {0,1,0,-1};

        int m = heightMap.size(); int n = heightMap[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        for(int i = 0;i < m;i++) {
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][n-1],i,n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for(int i = 0;i < n;i++) {
            pq.push({heightMap[0][i],0,i});
            pq.push({heightMap[m-1][i],m-1,i});
            visited[0][i] = visited[m-1][i] = true;
        }

        int answer = 0;
        while(!pq.empty()) {
            int minBoundaryHeight = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            for(int i = 0;i < 4;i++) {
                int xNew = x + x_new[i];
                int yNew = y + y_new[i];

                if(isValid(xNew,yNew,m,n) && !visited[xNew][yNew]) {
                    int nbhdHeight = heightMap[xNew][yNew];
                    visited[xNew][yNew] = true;
                    if(nbhdHeight < minBoundaryHeight) {
                        answer += minBoundaryHeight - nbhdHeight;
                    }
                    pq.push({max(nbhdHeight,minBoundaryHeight), xNew, yNew});
                }
            }
        }
        return answer;

    }
};
