class Solution {
public:
    int n;
    unordered_map<int,vector<int>>mp;
    vector<int>digitSum;
    int mod = 1e9 + 7;
    vector<vector<int>>dp;

    bool check(int num, int sum) {
        int temp = num;
        int sum1 = 0;
        while(temp) {
            sum1 += temp%10;
            temp/=10;
        }

        return sum == sum1;
    }

    int dpFunction(int i, int num) {
        if(i == n) return 1;
        if(num > 5000) return 0;

        if(dp[i][num] != -1) return dp[i][num];

        int ans = 0;

        if(check(num, digitSum[i])) {
            ans = (ans + dpFunction(i+1, num) % mod) % mod;
        }

        ans = (ans + dpFunction(i, num + 1) % mod) % mod;

        return dp[i][num] = ans;
    }

    

    int countArrays(vector<int>& digitSum) {
        n = digitSum.size();
        this->digitSum = digitSum;
        dp = vector<vector<int>>(n,vector<int>(5001,-1));
        return dpFunction(0,0);
    }
};
