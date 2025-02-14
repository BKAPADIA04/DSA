#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;
    vector<int>fact;

    int modular_mul(int a,int b) {
        return ((ll)(a % mod) * (b % mod)) % mod;
    }

    int binary_expo(int a,int b) {
        if(!b) return 1; // b == 0
        int res = binary_expo(a,b/2);
        if(b & 1) return modular_mul(a,modular_mul(res,res));
        else return modular_mul(res,res);
    }

    int modular_inverse(int a) {
        return binary_expo(a,mod-2); // fermat little theorem
    }

    void factorial() {
        fact.resize(100002,0);
        fact[0] = 1;
        for(int i = 1;i <= 100001;i++) {
            fact[i] = modular_mul(fact[i-1],i);
        }
    }

    int anagrams(string str) {
        int n = str.size();
        vector<int>freq(26);
        for(int i = 0;i < n;i++) {
            freq[str[i] - 97]++;
        }
        int deno = 1;
        for(int i = 0;i < 26;i++) {
            deno = modular_mul(deno,fact[freq[i]]);
        }

        return modular_mul(fact[n],modular_inverse(deno));
    }

    int countAnagrams(string s) {
        factorial();
        istringstream ss(s);
        string word; 
        int ans=1;

        while(ss >> word) {
            ans = modular_mul(ans,anagrams(word));
            cout << ans << endl;
        }
        return ans;
    }
};