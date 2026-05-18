class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxVal = 0;
        for (auto &row : matrix) {
            for (int val : row) {
                maxVal = max(maxVal, val);
            }
        }

        int ans = 0;

        for (int x = 1; x <= maxVal; x++) {
            vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));

            // pre = count of cells with value > x
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int greater = matrix[i][j] > x;

                    pre[i + 1][j + 1] = greater
                        + pre[i][j + 1]
                        + pre[i + 1][j]
                        - pre[i][j];
                }
            }

            auto query = [&](int r1, int c1, int r2, int c2) {
                r1 = max(r1, 0);
                c1 = max(c1, 0);
                r2 = min(r2, n - 1);
                c2 = min(c2, m - 1);

                if (r1 > r2 || c1 > c2) return 0;

                return pre[r2 + 1][c2 + 1]
                     - pre[r1][c2 + 1]
                     - pre[r2 + 1][c1]
                     + pre[r1][c1];
            };

            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    if (matrix[r][c] != x) continue;

                    int cnt = query(r - x, c - x, r + x, c + x);

                    // remove ignored corners
                    cnt -= query(r - x, c - x, r - x, c - x);
                    cnt -= query(r - x, c + x, r - x, c + x);
                    cnt -= query(r + x, c - x, r + x, c - x);
                    cnt -= query(r + x, c + x, r + x, c + x);

                    if (cnt == 0) ans++;
                }
            }
        }

        return ans;
    }
};
