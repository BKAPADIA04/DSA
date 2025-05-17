class Solution {
public:

    vector<int>dp;
    vector<vector<bool>>isPalin;

    // bool isPalin(string &s, int i, int j) {
    //     while(i <= j) {
    //         if(s[i] != s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    vector<vector<bool>>isPalindrome(string &s) {
        int n = s.size();
        vector<vector<bool>>answer(n,vector<bool>(n,false));
        for(int i = n - 1;i >= 0;i--) {
            for(int j = i;j < n;j++) {
                if(s[i] == s[j] && (j - i < 2 || answer[i+1][j-1])) {
                    answer[i][j] = true;
                }
            }
        }
        return answer;
    }

    int check(int i, string &s) {
        int n = s.size();
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for(int j = i;j < n;j++) {
            // if(!isPalin(s, i, j)) continue;
            if(!isPalin[i][j]) continue;
            int temp = 1 + check(j + 1, s);
            ans = min(ans,temp);
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        dp = vector<int>(s.size(),-1);
        isPalin = isPalindrome(s);
        return check(0,s) - 1;
    }
};
