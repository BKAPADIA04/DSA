class Solution {
public:

    int n, m;
    vector<vector<int>> pf;

    int getSum(int r1, int c1, int r2, int c2) {
        int ans = pf[r2][c2];

        if (r1 > 0)
            ans -= pf[r1 - 1][c2];

        if (c1 > 0)
            ans -= pf[r2][c1 - 1];

        if (r1 > 0 && c1 > 0)
            ans += pf[r1 - 1][c1 - 1];

        return ans;
    }

    int maxArea(vector<vector<int>>& a) {

        n = a.size();
        m = a[0].size();

        int z = min(n, m);

        // n x m prefix sum
        pf.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                pf[i][j] = a[i][j];

                if (i > 0)
                    pf[i][j] += pf[i - 1][j];

                if (j > 0)
                    pf[i][j] += pf[i][j - 1];

                if (i > 0 && j > 0)
                    pf[i][j] -= pf[i - 1][j - 1];
            }
        }

        // v[k] = starting positions of valid k x k squares
        vector<vector<pair<int, int>>> v(z + 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                for (int k = 1;
                     i + k <= n && j + k <= m;
                     k++) {

                    int s = getSum(
                        i,
                        j,
                        i + k - 1,
                        j + k - 1
                    );

                    if (s == k * k) {
                        v[k].push_back({i, j});
                    }
                    else {
                        // If k x k isn't all 1,
                        // larger square cannot be valid.
                        break;
                    }
                }
            }
        }

        // Find maximum non-overlapping square
        for (int k = z; k >= 1; k--) {

            if (v[k].size() < 2)
                continue;

            int minX = n, maxX = -1;
            int minY = m, maxY = -1;

            for (auto [x, y] : v[k]) {

                minX = min(minX, x);
                maxX = max(maxX, x);

                minY = min(minY, y);
                maxY = max(maxY, y);
            }

            // Separate vertically OR horizontally
            if (maxX - minX >= k ||
                maxY - minY >= k) {

                return k * k;
            }
        }

        return 0;
    }
};
