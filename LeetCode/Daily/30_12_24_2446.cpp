class Solution {
public:

    void print(vector<int>dp,int high) {
        for(int i = 0;i <= high;i++) cout << dp[i] << " " ;
        cout << endl;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod = 1000000007;
        vector<int>dp(100001,0);
        dp[zero]++; dp[one]++;
        for(int i = 1;i <= high;i++) {
            int zeroth = 0;
            int oneth = 0;
            if(i - zero >= 0) {
                zeroth = dp[i-zero] % mod;
            }
            if(i-one >= 0) {
                oneth = dp[i-one] % mod;
            }
            dp[i] = (dp[i] + (zeroth + oneth) % mod) % mod;
        }

        int answer = 0;
        for(int i = low;i <= high;i++) {
            answer = (answer + dp[i]) % mod;
        }
        print(dp,high);
        return answer;
    }
};
