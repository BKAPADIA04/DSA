class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int m = artifacts.size();
        vector<vector<int>> grid(n, vector<int>(n, 0));

        for(int i = 0;i < dig.size();i++) {
            grid[dig[i][0]][dig[i][1]] = 1;
        }

        vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                prefixSum[i][j] = prefixSum[i - 1][j]+prefixSum[i][j - 1] - prefixSum[i-1][j-1]+grid[i-1][j-1];     
            }
        }

        // for(auto it:prefixSum) {
        //     for(auto it1:it) cout << it1 << " ";
        //     cout << endl;
        // }

        int ans = 0;
        for(int i = 0;i < m;i++) {
            int x1 = artifacts[i][0];
            int y1 = artifacts[i][1];
            int x2 = artifacts[i][2];
            int y2 = artifacts[i][3];

            int requiredArea = (x2 - x1 + 1) * (y2 - y1 + 1);
            int dug = prefixSum[x2+1][y2+1] - prefixSum[x2+1][y1] - prefixSum[x1][y2+1] + prefixSum[x1][y1];

            // cout << requiredArea << " " << dug << endl;
            if(requiredArea == dug) ans++;
        }
        return ans;
    }
};
