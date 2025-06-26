class Solution {
public:
    int longestSubsequence(string s, int k) {
        reverse(s.begin(),s.end());
        int n = s.size();
        vector<int>dp(n,1);
        vector<int>value(n,0);
        for(int i = 0;i < n;i++) {
            if(s[i] == '1') value[i] = 1;
        }

        for(int i = 1;i < n;i++) {
            for(int j = i - 1;j >= 0; j--) {
                long long temp = value[j];
                int len = dp[j];

                // temp = temp + ((long long)(s[i] - '0') * (long long)pow(2,len));

                if(temp + ((s[i] - '0') * pow(2,len)) <= k) {
                    if(len + 1 > dp[i]) {
                        dp[i] = len + 1;
                        value[i] = temp + ((s[i] - '0') * pow(2,len));
                    }
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
