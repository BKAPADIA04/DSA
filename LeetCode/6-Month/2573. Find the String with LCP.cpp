class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string answer(n, 'a');
        char mini = 'b';

        for(int i = 1;i < n;i++) {
            bool flag = false;
            for(int j = 0;j < i;j++) {
                if(lcp[i][j] > 0) {
                    flag = true;
                    answer[i] = answer[j];
                    break;
                }
            }

            if(!flag) answer[i] = mini++;
        }

        for(int i=0;i<n;i++)    if(answer[i]>'z')  return "";
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i = n - 1;i >= 0;i--) {
            for(int j = n - 1;j >= 0;j--) {
                if(answer[i] == answer[j]) {
                    dp[i][j] = 1 + ((i + 1 < n && j + 1 < n) ? dp[i+1][j+1] : 0);
                }
            }
        }

        for(int i = n - 1;i >= 0;i--) {
            for(int j = n - 1;j >= 0;j--) {
                if(dp[i][j] != lcp[i][j]) return "";
            }
        }
        return answer;
    }
};
