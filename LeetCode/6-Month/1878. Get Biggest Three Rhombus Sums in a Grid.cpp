class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int>s;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                int len = min(i,j); 
                s.insert(grid[i][j]);
                for(int k = 1; ;k++) {
                    int bottom = i + 2*k;
                    int right = j + k;
                    int left = j - k;
                    if(bottom >= m || right >= n || left < 0) break;
                    int sum = 0;

                    int x = i; int y = j;
                    for(int t = 0;t < k;t++) {
                        sum += grid[x+t][y+t];
                        sum += grid[x+k+t][y+k-t];
                        sum += grid[x+2*k-t][y-t];
                        sum += grid[x+k-t][y-k+t];
                    }
                    s.insert(sum);
                }
            }
        }

        vector<int>answer;
        for(auto it = s.rbegin(); it != s.rend();it++) {
            if(answer.size() == 3) break;
            answer.push_back(*it);
        }
        return answer;
    }
};
