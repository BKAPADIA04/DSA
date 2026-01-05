#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll m = matrix.size();
        ll n = matrix[0].size();

        ll sum = 0ll;
        ll largestMin = 1e5 + 1; bool flag = true; bool zeroFlag = false;
        for(ll i = 0;i < m;i++) {
            for(ll j = 0;j < n;j++) {
                sum += abs(matrix[i][j]);
                largestMin = min(largestMin, 1ll*abs(matrix[i][j]));
                if(matrix[i][j] < 0) {
                    flag = !flag;
                }
                if(matrix[i][j] == 0) {
                    zeroFlag = true;
                }
            }
        }
        if(flag || zeroFlag) return sum;
        return sum - 2 * largestMin;
    }
};
