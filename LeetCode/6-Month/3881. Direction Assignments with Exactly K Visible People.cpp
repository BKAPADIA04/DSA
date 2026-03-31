class Solution {
public:

    int MOD = 1e9 + 7;
    vector<long long> fact, inv;
    
    int comb(int n, int r) {
        return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
    }

    long long pow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    void init(int n) {
        fact.resize(n + 1);
        inv.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        inv[n] = pow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }

    int countVisiblePeople(int n, int pos, int k) {
        int left = pos;
        int right = n - pos - 1;
        int ans = 0;
        
        init(n);
        
        for (int i = max(0, k - right); i <= min(left, k); i++) {
            ans = (ans + 1ll * comb(left, i) * comb(right, k - i)) % MOD;
        }

        return (ans * 2) % MOD;
    }
};
