class Solution {
public:

    pair<int,int>getPair(int num) {
        int fives = 0; int twos = 0;
        while((num % 5) == 0) {
            num/=5;
            fives++;
        }
        while((num % 2) == 0) {
            num/=2;
            twos++;
        }

        return {twos,fives};
    }

    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<pair<int,int>>>top(m,vector<pair<int,int>>(n,{0,0}));
        vector<vector<pair<int,int>>>left(m,vector<pair<int,int>>(n,{0,0}));

        for(int i = 0; i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(i == 0) {
                    top[i][j] = getPair(grid[i][j]);
                }
                else {
                    pair<int,int>p = getPair(grid[i][j]);
                    top[i][j].first = top[i-1][j].first + p.first;
                    top[i][j].second = top[i-1][j].second + p.second;
                }
            }
        }

        for(int i = 0; i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(j == 0) {
                    left[i][j] = getPair(grid[i][j]);
                }
                else {
                    pair<int,int>p = getPair(grid[i][j]);
                    left[i][j].first = left[i][j-1].first + p.first;
                    left[i][j].second = left[i][j-1].second + p.second;
                }
            }
        }

        int answer = 0;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                pair<int,int>down,right;
                pair<int,int>p = getPair(grid[i][j]);
                down.first = top[m-1][j].first - top[i][j].first;
                down.second = top[m-1][j].second - top[i][j].second;

                right.first = left[i][n-1].first - left[i][j].first;
                right.second = left[i][n-1].second - left[i][j].second;

                // down + left
                answer = max(answer, min(down.first + left[i][j].first, down.second + left[i][j].second));
                // down + right
                answer = max(answer, min(down.first + right.first + p.first, down.second + right.second + p.second));

                // top + left
                answer = max(answer, min(top[i][j].first + left[i][j].first - p.first, top[i][j].second + left[i][j].second - p.second));

                // top + right
                answer = max(answer, min(top[i][j].first + right.first, top[i][j].second + right.second));
            }
        }
        return answer;
    }
};
