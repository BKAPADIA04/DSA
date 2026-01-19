#define ll long long
class Solution {
public:
    vector<vector<ll>>preSum;
    ll m,n;

    bool check(int threshold, ll mid) {
        for(ll i = 0; i < m;i++) {
            for(ll j = 0;j < n;j++) {
                if(i + mid <= m && j + mid <= n) {
                    ll area = preSum[i+mid][j+mid] - preSum[i+mid][j] - preSum[i][j+mid] + preSum[i][j];
                    // cout << i << " " << j << " " << area << endl;
                    if(area <= threshold) return true;
                }
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m = mat.size();
        n = mat[0].size();
        preSum = vector<vector<ll>>(m+1,vector<ll>(n+1,0));
        for(int i = 1;i <= m;i++) {
            for(int j = 1;j <= n;j++) {
                preSum[i][j] = preSum[i][j-1] + preSum[i-1][j] - preSum[i-1][j-1] + mat[i-1][j-1];
            }
        } 

        // for(int i = 0;i <= m;i++) {
        //     for(int j = 0;j <= n;j++) {
        //         cout << preSum[i][j] << " ";
        //     }
        //     cout << endl;
        // } 

        ll low = 0; ll high = min(m,n);
        ll ans = -1;
        while(low <= high) {
            ll mid = (low + high)/2;
            if(check(threshold, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if(ans == -1) return 0;
        return ans;
    }
};
