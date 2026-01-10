class Solution {
public:

    int n,m;
    vector<vector<int>>dp;

    int check(string &s1, string &s2, int i, int j) {

        if(i == n && j == m) return 0;

        if(i == n) {
            int temp = 0;
            for(int k = j;k < m;k++) {
                temp += (int)(s2[k]);
            }
            return temp;
        }

        if(j == m) {
            int temp = 0;
            for(int k = i;k < n;k++) {
                temp += (int)(s1[k]);
            }
            return temp;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        int answer;

        if(s1[i] == s2[j]) {
            answer = check(s1,s2,i+1,j+1);
        }
        else {
            int opt1 = (int)(s1[i]) + (int)(s2[j]) + check(s1,s2,i+1,j+1);
            int opt2 = (int)(s1[i]) + check(s1,s2,i+1,j);
            int opt3 = (int)(s2[j]) + check(s1,s2,i,j+1);

            answer = min({opt1, opt2, opt3});
        }

        return dp[i][j] = answer;
    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();

        // cout << s1[0] << endl;

        dp = vector<vector<int>>(n,vector<int>(m,-1));
        return check(s1,s2,0,0);
    }
};
