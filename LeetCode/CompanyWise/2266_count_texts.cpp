class Solution {
public:

    int mod = 1e9 + 7;
    vector<vector<int>>dp;

    int check(int digit, int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[digit][n] != -1) return dp[digit][n]; 

        int ans = 0;
        ans = (ans + check(digit,n - 1)) % mod;
        ans = (ans + check(digit,n - 2)) % mod;
        ans = (ans + check(digit,n - 3)) % mod;
        if(digit == 7 || digit == 9) ans = (ans + check(digit, n - 4)) % mod;

        return dp[digit][n] = ans % mod;
    }

    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        dp = vector<vector<int>>(10,vector<int>(1e5 + 1,-1));
        int ans = 1;
        int count = 1; char ch = pressedKeys[0];
        for(int i = 1; i < n;i++) {
            if(pressedKeys[i] != ch) {
                ans = ((long long) ans * (long long)check(ch - '0',count) % mod) % mod;
                count = 0;
                ch = pressedKeys[i];
            }
            count++;
        }
        ans = ((long long)ans * (long long) check(ch - '0',count) % mod) % mod;
        return ans % mod;
    }
};

// class Solution {
// public:
//     int dp[100005];
//     int mod = 1e9+7;
//     int solve(string &str, int idx) {
//         if(idx == str.length()) return 1;
//         if(dp[idx] != -1) return dp[idx];
//         int maxKeyPress = (str[idx] == '7' || str[idx] == '9') ? 4 : 3;
//         long long currIndex = idx, pressFrequency = 1, ans = 0;
//         while(pressFrequency <= maxKeyPress && str[currIndex] == str[idx]) {
//             ++currIndex;
//             ++pressFrequency;
//             ans += solve(str, currIndex) % mod;
//         }
//         return dp[idx] = ans%mod;
//     }
//     int countTexts(string pressedKeys) {
//         memset(dp, -1, sizeof(dp));
//         return solve(pressedKeys, 0) % mod;
//     }
// };
