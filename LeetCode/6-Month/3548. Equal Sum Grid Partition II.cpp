#define ll long long
class Solution {
public:

    bool check(vector<ll>&freq, vector<vector<int>>&grid, int r1, int c1, int r2, int c2, ll diff) {
        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;
        if(rows * cols == 1) return false;

        if(rows == 1) {
            return grid[r1][c1] == diff || grid[r1][c2] == diff;
        }

        if(cols == 1) {
            return grid[r1][c1] == diff || grid[r2][c1] == diff;
        }

        return freq[diff] > 0;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        ll totalSum = 0ll;

        vector<ll>top(100001,0), bottom(100001,0), left(100001,0), right(100001,0);
        for(ll i = 0;i < m;i++) {
            for(ll j = 0;j < n;j++) {
                totalSum += grid[i][j];
                bottom[grid[i][j]]++;
                right[grid[i][j]]++;
            }
        }

        ll sumTop = 0ll;
        for(ll i = 0;i < m - 1;i++) {
            for(ll j = 0;j < n;j++) {
                sumTop += grid[i][j];
                top[grid[i][j]]++;
                bottom[grid[i][j]]--;
            }

            ll sumBottom = totalSum - sumTop;
            if(sumTop == sumBottom) return true;

            ll diff = abs(sumTop - sumBottom);
            if(diff >= 100000) continue;
            if(sumTop > sumBottom) {
                if(check(top, grid, 0, 0, i, n-1, diff)) return true;
            }
            else {
                if(check(bottom, grid, i+1, 0, m-1, n-1, diff)) return true;
            }
        }

        ll sumLeft = 0ll;
        for(ll j = 0;j < n - 1;j++) {
            for(ll i = 0;i < m;i++) {
                sumLeft += grid[i][j];
                left[grid[i][j]]++;
                right[grid[i][j]]--;
            }

            ll sumRight = totalSum - sumLeft;
            if(sumLeft == sumRight) return true;

            ll diff = abs(sumRight - sumLeft);
            if(diff >= 100000) continue;
            if(sumLeft > sumRight) {
                if(check(left, grid, 0, 0, m-1, j, diff)) return true;
            }
            else {
                if(check(right, grid, 0, j+1, m-1, n-1, diff)) return true;
            }
        }

        return false;
    }   
};
