class Solution {
public:

    int n;
    string s;

    vector<vector<vector<int>>>dp;

    int check(int i, int value, int isZero) {
        if(i >= n) {
            if(value >= 1 && value <= 26 && !isZero) return 1ll;
            return 0ll;
        }

        if(dp[i][value][isZero + 1] != -1) return dp[i][value][isZero + 1];

        // cout << i << " " << value << " " << isZero << endl;

        int ans = 0;
        if(isZero != -1) {
            int opt1Val = value * 10 + (s[i] - '1') + 1;
            if(!isZero && opt1Val <= 26) {
                // cout << i << " " << opt1Val << endl;
                ans += check(i+1, opt1Val,isZero);
            }
        }

        int opt2Val = (s[i] - '1') + 1;
        int newIsZero = 0;
        if(s[i] == '0') newIsZero = 1;

        if(!newIsZero && opt2Val <= 26) {
            ans += check(i+1, opt2Val,newIsZero);
        }

        return dp[i][value][isZero + 1] = ans;
    }

    int numDecodings(string s) {
        n = s.size();
        this->s = s;
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(27,vector<int>(3,-1)));
        return check(0,0,-1);
    }
};

/*class Solution {
public:
    int numDecodings(string s) {
        
        a character is be coded with either 1 or 2 characters
        -> looking at a character of the string -> there might be 2 ways that it can be decoded
            => it can be decoded alone or as a part of a pair of characters
        => dynamic programming
        for character s[i] -> try to decode it alone or decode s[i - 1:i]
            => dp[i] = dp[i - 1] + dp[i - 2]
        => dp[i] is the number of ways I can decode the string s[0:i]
        
        int n = s.length();
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (i >= 2) {
                if (s[i - 1] <= '6' && s[i - 2] >= '1' && s[i - 2] <= '2') {
                    dp[i] += dp[i - 2];
                } else if (s[i - 2] == '1') {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[n];
    }
};*/
