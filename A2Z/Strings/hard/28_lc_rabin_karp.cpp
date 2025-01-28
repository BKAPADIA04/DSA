#define ll long long
class Solution {
public:
    ll MOD_1 = 1e9 + 7;
    ll MOD_2 = 1e9 + 33;

    pair<ll,ll> hashValue(string str,ll RADIX_1,ll RADIX_2,ll m) {
        ll hash_1 = 0; ll hash_2 = 0;
        ll factor_1 = 1; ll factor_2 = 1;

        for(ll i = m - 1;i >= 0;i--) {
            hash_1 += ((str[i] - 'a') * factor_1) % MOD_1;
            factor_1 = (factor_1 * RADIX_1) % MOD_1;

            hash_2 += ((str[i] - 'a') * factor_2) % MOD_2;
            factor_2 = (factor_2 * RADIX_2) % MOD_2;
        }

        return {hash_1 % MOD_1,hash_2 % MOD_2};
    }

    int strStr(string haystack, string needle) {
        ll n = haystack.size();
        ll m = needle.size();
        if(m > n) return -1;

        ll MAX_VALUE_1 = 1; ll MAX_VALUE_2 = 1; // to store (26)^m
        ll RADIX_1 = 26; ll RADIX_2 = 27;

        for(ll i = 1;i <= m;i++) {
            MAX_VALUE_1 = (MAX_VALUE_1 * RADIX_1) % MOD_1;
            MAX_VALUE_2 = (MAX_VALUE_2 * RADIX_2) % MOD_2;
        }

        pair <ll,ll> hashNeedle = hashValue(needle,RADIX_1,RADIX_2,m);
        pair <ll,ll> hashHay = {0,0};
        for(ll i = 0;i <= n-m;i++) {
            if(i == 0) {
                hashHay = hashValue(haystack,RADIX_1,RADIX_2,m);
            }
            else {
                hashHay.first = (((hashHay.first * RADIX_1) % MOD_1) - (((haystack[i-1] - 'a') * MAX_VALUE_1) % MOD_1) + (haystack[i+m-1] - 'a') + MOD_1) % MOD_1;
                hashHay.second = (((hashHay.second * RADIX_2) % MOD_2) - (((haystack[i-1] - 'a') * MAX_VALUE_2) % MOD_2) + (haystack[i+m-1] - 'a') + MOD_2) % MOD_2;
            }

            if(hashHay.first == hashNeedle.first && hashHay.second == hashNeedle.second) return i; 
        }
    return -1;
    }
};