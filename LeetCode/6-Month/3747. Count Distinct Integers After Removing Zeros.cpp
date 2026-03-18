class Solution {
public:
    vector<int> digit;
    long long dp[16][2][2][2];

    long long dfs(int pos, int tight, int leadZero, int foundZero) {
        if(pos == (int)digit.size()) return foundZero == 0;

        long long &ans = dp[pos][tight][leadZero][foundZero];
        if(ans != -1) return ans;

        ans = 0;
        int range = tight ? digit[pos] : 9;

        for(int i=0; i<=range; i++) {
            int nextTight = tight && (i == range);
            int nextLeadZero = leadZero && (i == 0);
            bool fndZero = foundZero || (!nextLeadZero && i == 0);

            ans += dfs(pos+1, nextTight, nextLeadZero, fndZero);
        }

        return ans;
    }

    long long cal(long long num) {
        while(num > 0) {
            digit.push_back(num%10);
            num /= 10;
        }

        reverse(digit.begin(), digit.end());

        memset(dp, -1, sizeof(dp));

        return dfs(0, 1, 1, 0);
    }
    long long countDistinct(long long n) {
        //position of digit, 16, tight, leading zero

        return cal(n)-1;
    }
};
