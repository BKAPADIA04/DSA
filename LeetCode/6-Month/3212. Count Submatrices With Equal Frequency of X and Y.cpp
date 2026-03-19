class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>preSum(m,vector<int>(n,0));
        vector<vector<int>>preSumX(m,vector<int>(n,0));

        int answer = 0;
        
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                int sum = 0; int sumX = 0;
                if(grid[i][j] == 'X') {
                    sum = 1;
                    sumX = 1;
                } else if(grid[i][j] == 'Y') {
                    sum -= 1;
                }

                if(i - 1 >= 0) {
                    sum += preSum[i-1][j];
                    sumX += preSumX[i-1][j];
                }
                if(j - 1 >= 0) {
                    sum += preSum[i][j-1];
                    sumX += preSumX[i][j-1];
                }
                if(i - 1 >= 0 && j - 1 >= 0) {
                    sum -= preSum[i-1][j-1];
                    sumX -= preSumX[i-1][j-1];
                }

                preSum[i][j] = sum;
                preSumX[i][j] = sumX;

                if(preSum[i][j] == 0 && preSumX[i][j] > 0) answer += 1;
            }
        }

        return answer;
    }
};
