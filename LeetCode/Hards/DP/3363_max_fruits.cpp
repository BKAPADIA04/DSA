class Solution {
public:

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i < j && i + j < n - 1) fruits[i][j] = 0;
                if(j < i && i + j < n - 1) fruits[i][j] = 0;
            }
        }

        int ans = 0;
        for(int i = 0;i < n;i++) {
            ans += fruits[i][i];
        }

        for(int i = 1;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                fruits[i][j] += max({fruits[i-1][j-1], fruits[i-1][j], (j + 1 < n) ? fruits[i-1][j+1] : 0});
            }
        }

        for(int j = 1;j < n;j++) {
            for(int i = j + 1;i < n;i++) {
                fruits[i][j] += max({fruits[i-1][j-1], fruits[i][j-1], (i + 1 < n) ? fruits[i+1][j-1] : 0});
            }
        }

        return ans + fruits[n - 2][n - 1] + fruits[n - 1][n - 2];

    }
};
