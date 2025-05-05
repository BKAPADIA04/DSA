class Solution {
public:

    vector<pair<int,int>>v;
    int n;
    string word;

    vector<vector<vector<int>>>dp;

    int check(int i, int pos1, int pos2) {
        if(i >= n) return 0;

        if(dp[i][pos1 + 1][pos2 + 1] != -1) return dp[i][pos1 + 1][pos2 + 1];
        int ch = word[i] - 'A';

        int ans = INT_MAX;

        if(pos1 == -1) {
            ans = min(ans,check(i + 1, ch, pos2));
        }

        if(pos2 == -1) {
            ans = min(ans,check(i + 1, pos1, ch));
        }

        // finger1
        if(pos1 != -1) {
            int dist1 = abs(v[pos1].first - v[ch].first) + abs(v[pos1].second - v[ch].second);
            ans = min(ans, dist1 + check(i + 1, ch, pos2));
        }

        // finger2
        if(pos2 != -1) {
            int dist2 = abs(v[pos2].first - v[ch].first) + abs(v[pos2].second - v[ch].second);
            ans = min(ans, dist2 + check(i + 1, pos1, ch));
        }

        return dp[i][pos1 + 1][pos2 + 1] = ans;
    }

    int minimumDistance(string w) {
        n = w.size();
        word = w;
        int x = 0; int y = 0;
        for(int i = 0;i < 26;i++) {
            v.push_back({x,y});
            y++;
            if(y == 6) {
                x++; y = 0;
            }
        }
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(27,vector<int>(27,-1)));
        return check(0,-1,-1);
    }
};
