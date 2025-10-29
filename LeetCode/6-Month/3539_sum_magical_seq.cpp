#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;
    ll n;

    map<tuple<ll, ll , ll, ll>, ll> memo;

    vector<ll> fact;
    vector<ll> invFact;

    ll nCr(int n, int r) {
        //nCr = n! * inv(n-r)! * inv(r)!
        return (((fact[n] * invFact[r]) % mod) * invFact[n-r]) % mod;
    }
    
    ll power(ll a, ll b) {
        if(b == 0) return 1ll; 
        
        ll half = power(a,b/2) % mod;
        ll prod = (half * half) % mod;
        if(b % 2 == 1) prod = (prod * a) % mod;

        return prod % mod;
    }

    ll check(ll binarySum, ll m, ll k,ll i, vector<int>&nums) {
        
        if(m == 0 && __builtin_popcount(binarySum) == k) {
            return 1ll;
        }

        if(m == 0 || i >= n) return 0ll;

        auto key = make_tuple(binarySum, m, k, i);

        if(memo.count(key)) {
            return memo[key];
        }

        ll totalSum = 0ll;
        
        totalSum = (totalSum + check(binarySum >> 1, m, k - (binarySum & 1), i+1,nums) % mod) % mod;

        for(ll freq = 1;freq <= m;freq++) {
            ll newBinarySum = binarySum + freq;
            ll prod = check(newBinarySum >> 1, m - freq, k - (newBinarySum & 1), i+1,nums) % mod;
            prod = (power(nums[i],freq) % mod * prod % mod) % mod;
            prod = (nCr(m,freq) * prod) % mod;
            totalSum = (totalSum + prod) % mod;
        }

        return memo[key] = totalSum;
    }


    int magicalSum(int m, int k, vector<int>& nums) {
        n = nums.size();

        fact = vector<ll>(m + 1,1);
        invFact = vector<ll>(m + 1,1);


        for(ll i = 1;i <= m;i++) fact[i] = (fact[i-1] * i) % mod;
        for(int i = 0; i <= m; i++) {
            invFact[i] = power(fact[i], mod-2);
        }
        
        return (int)(check(0,m,k,0,nums) % mod);
    }
};
