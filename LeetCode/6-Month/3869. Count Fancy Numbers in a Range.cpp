#define ll long long
class Solution {
public:

    ll dp[20][2][2][4][11][150]; // idx, tight, leading zero, direction, prev, sum

    ll check(string &str, ll idx, ll tight, ll lz, ll dir, ll prev, ll sum) {
        if(idx == str.size()) {
            if(lz) return 0ll;
            if(dir == 0) return 1ll;
            if(dir == 1) return 1ll;
            if(dir == 2) return 1ll;

            string sumCheck = to_string(sum);

            bool flagI = true; bool flagD = true;
            for(int i = 1;i < sumCheck.size();i++) {
                if(sumCheck[i] >= sumCheck[i-1]) flagD = false;
                if(sumCheck[i] <= sumCheck[i-1]) flagI = false;
            }

            if(flagI || flagD) return 1ll;
            return 0ll;
        }

        if(dp[idx][tight][lz][dir][prev][sum] != -1ll) return dp[idx][tight][lz][dir][prev][sum];

        ll ans = 0ll;

        ll limit = (tight == 1) ? (str[idx] - '0') : 9;
        for(ll i = 0;i <= limit;i++) {
            if(lz && (i == 0)) {
                ans += check(str, idx + 1, tight & (i == (str[idx] - '0')), lz, dir, prev, sum);
            }
            else if(lz) {
                ans += check(str, idx + 1, tight & (i == (str[idx] - '0')), 0, 0, i, sum + i);
            }
            else if(i > prev && (dir == 0 || dir == 1)) {
                ans += check(str, idx + 1, tight & (i == (str[idx] - '0')), lz, 1, i, sum + i);
            }
            else if(i < prev && (dir == 0 || dir == 2)) {
                ans += check(str, idx + 1, tight & (i == (str[idx] - '0')), lz, 2, i, sum + i);
            }
            else {
                ans += check(str, idx + 1, tight & (i == (str[idx] - '0')), lz, 3, i, sum + i);
            }
        }

        return dp[idx][tight][lz][dir][prev][sum] = ans;
    }


    long long countFancy(long long l, long long r) {
       string right = to_string(r);
       memset(dp, -1ll, sizeof(dp));
       ll rightAns = check(right, 0, 1, 1, 3, 10, 0);

       string left = to_string(l-1);
       memset(dp, -1ll, sizeof(dp)); 
       ll leftAns = check(left, 0, 1, 1, 3, 10, 0);

       return rightAns - leftAns;
    }
};
