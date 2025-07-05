// #define ll long long
// class Solution {
// public:

//     ll k;
//     ll mod = 1e9 + 7;
//     ll dp[11][2][11][11][21][2];

//     ll check(string &s, ll index, ll tight, ll even, ll odd, ll rem, ll lead) {
//         if(index == s.size()) {
//             ll n = s.size();
//             if(n & 1) return 0;
//             if(even != odd) return 0;
//             if(rem == 0 && lead == 0) return 1;
//             return 0;
//         }

//         if(dp[index][tight][even][odd][rem][lead] != -1) return dp[index][tight][even][odd][rem][lead];

//         ll ans = 0ll;

//         ll limit = (tight == 1 ? s[index] - '0' : 9);
//         for(ll i = 0;i <= limit;i++) {
//             ll newTight = tight & (i == limit);
//             ll newRem = (rem * 10 + i) % k;
//             ll newLead = lead & (i == 0);
//             ll newOdd = odd + (newLead == 0 && i % 2 == 1);
//             ll newEven = even + (newLead == 0 && i % 2 == 0);

//             ans = ans + check(s, index + 1, newTight, newEven, newOdd, newRem, newLead);
//             // ans %= mod;
//         }
//         return dp[index][tight][even][odd][rem][lead] = ans;
//     }

//     int numberOfBeautifulIntegers(int low, int high, int k_) {
//         k = (ll)k_;
//         string r = to_string(high);
//         string l = to_string(low-1);
//         memset(dp,-1,sizeof(dp));
//         ll ans2 = check(r,0,1,0,0,0,1);
//         memset(dp,-1,sizeof(dp));
//         ll ans1 = check(l,0,1,0,0,0,1);

//         return (ans2 - ans1);
//     }
// };
int dp[10][2][20][10][10][2];
class Solution {
public:
    string num;
    int k;
    int fun(int pos, bool tight,int modk, int odd, int even, bool Lzero){
        if(pos == num.size()){
            return (modk == 0 and (odd == even) and (Lzero == false));
        }
        if( dp[pos][tight][modk][odd][even][Lzero] != -1) return  dp[pos][tight][modk][odd][even][Lzero];
        int limit = tight ? num[pos] -'0' : 9;
        int ans = 0;
        for(int i = 0; i <= limit ; i++){
            int newtight = tight && (i==limit);
            bool newLzero = Lzero && (i == 0);
            int newodd = odd + (i%2 == 1);
            int neweven = even + (!newLzero and i%2 == 0);
            ans += (fun(pos+1,newtight,(modk*10 + i)%k, newodd, neweven, newLzero));
        }
        return dp[pos][tight][modk][odd][even][Lzero] =  ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp,-1,sizeof(dp));
        this->k = k;
        num = to_string(low-1);
        auto ans1 = fun(0,true,0,0,0,true);
        memset(dp,-1,sizeof(dp));
        num = to_string(high);
        auto ans2 = fun(0,true,0,0,0,true);
        return ans2- ans1;
    }
};
