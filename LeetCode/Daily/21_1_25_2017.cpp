#define ll long long
class Solution {
public:

    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<ll>suff(n+1,0),pre(n+1,0);
        for(int i = n-1;i >= 0;i--) {
            suff[i] = suff[i+1] + grid[0][i];
        }
        for(int i = 1;i <= n;i++) {
            pre[i] = pre[i-1] + grid[1][i-1];
        }

        ll answer = LONG_LONG_MAX;
        for(int i = 1;i <= n;i++) {
            ll temp = max(suff[i],pre[i-1]);
            answer = min(answer,temp);
            cout << answer << endl;
        }
        return answer;
    }
};
