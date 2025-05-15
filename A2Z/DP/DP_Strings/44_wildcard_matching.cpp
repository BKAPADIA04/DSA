class Solution {
public:

    bool isAllStars(string &str, int i) {
        for(int j = 0;j <= i;j++) {
            if(str[j] != '*') return false;
        }
        return true;
    }

    vector<vector<int>>dp;

    bool check(string s, string p, int i, int j) {
        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0) return isAllStars(p,j);

        if(dp[i][j] != -1) return dp[i][j];

        bool answer = false;
        if(s[i] == p[j] || p[j] == '?') {
            answer |= check(s,p,i - 1,j - 1);
        }
        else if(p[j] == '*') {
            answer |= check(s,p,i - 1,j);
            answer |= check(s,p,i,j - 1);
        }
        // else return false;
        return dp[i][j] = answer;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        dp = vector<vector<int>>(n,vector<int>(m,-1));
        // return check(s,p,n - 1,m - 1);

        vector<vector<bool>>dp1(n + 1,vector<bool>(m + 1,false));
        dp1[0][0] = true;

        vector<bool>prev(m + 1,false);
        prev[0] = true;
        
        for(int i = 1;i <= n;i++) dp1[i][0] = false;
        for(int i = 1;i <= m;i++) {
            prev[i] = isAllStars(p,i - 1);
        }

        for(int i = 1;i <= n;i++) {
            vector<bool>curr(m + 1,false);
            for(int j = 1;j <= m;j++) {
                bool answer = false;
                if((s[i - 1] == p[j - 1]) || (p[j - 1] == '?')) {
                    answer |= prev[j - 1];
                }
                else if(p[j - 1] == '*') {
                    answer |= prev[j];
                    answer |= curr[j - 1];
                }

                curr[j] = answer;
            }
            prev = curr;
        }
        return prev[m];
    }
};
