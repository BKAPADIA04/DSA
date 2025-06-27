#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int minSum, maxSum;
string s1, s2;
vector<vector<vector<int>>> dp;

int digitDP(int pos, bool tight, int sum, const string &bound) {
    if (sum > maxSum) return 0;
    if (pos == bound.size()) {
        return (sum >= minSum) ? 1 : 0;
    }

    if (dp[pos][tight][sum] != -1) return dp[pos][tight][sum];

    int limit = tight ? (bound[pos] - '0') : 9;
    int ans = 0;

    for (int digit = 0; digit <= limit; ++digit) {
        bool newTight = (tight && digit == limit);
        ans = (ans + digitDP(pos + 1, newTight, sum + digit, bound)) % MOD;
    }

    return dp[pos][tight][sum] = ans;
}

int countInRange(string low, string high) {
    while (low.size() < high.size()) low = '0' + low;

    // Count numbers ≤ high
    dp.assign(high.size(), vector<vector<int>>(2, vector<int>(maxSum + 1, -1)));
    int countHigh = digitDP(0, true, 0, high);

    // Count numbers < low
    dp.assign(low.size(), vector<vector<int>>(2, vector<int>(maxSum + 1, -1)));
    int countLow = digitDP(0, true, 0, low);

    // Check if 'low' itself should be included
    int sumLow = 0;
    for (char c : low) sumLow += (c - '0');
    bool includeLow = (sumLow >= minSum && sumLow <= maxSum);

    int result = (countHigh - countLow + MOD) % MOD;
    if (includeLow) result = (result + 1) % MOD;

    return result;
}

int main() {
    cin >> s1 >> s2;
    cin >> minSum >> maxSum;

    int ans = countInRange(s1, s2);
    cout << ans << endl;

    return 0;
}
