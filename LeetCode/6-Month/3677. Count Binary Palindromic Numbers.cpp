#define ll long long
class Solution {
public:

    vector<int>digits;
    ll dp[64][64][2][2];

    ll check(int left, int right, int tight, int backTight) {
        if(left > right) {
            return (!tight || (tight && backTight));
        }

        if(dp[left][right][tight][backTight] != -1ll) return dp[left][right][tight][backTight];

        ll ans = 0ll;

        int limit = tight ? digits[left] : 1;

        for(ll d = 0;d <= limit;d++) {
            if(left == 0 && d == 0) continue;
            int nextBackTight = backTight;
            if(nextBackTight) {
                nextBackTight = (d <= digits[right]);
            }
            else {
                nextBackTight = (d < digits[right]);
            }

            ans += check(left + 1, right - 1, tight && (d == (digits[left])), nextBackTight);
        }

        return dp[left][right][tight][backTight] = ans;
    }

    int countBinaryPalindromes(long long n) {
        ll temp = n;
        while(temp) {
            int rem = temp % 2;
            digits.push_back(rem);
            temp /= 2;
        }

        reverse(digits.begin(), digits.end());
        memset(dp, -1ll, sizeof(dp));

        ll answer = 1ll;
        for(ll i = 1;i <= (int)digits.size();i++) {
            answer += check(0, i - 1, (i == (int)digits.size()), 1);
        }

        return answer;
    }
};
