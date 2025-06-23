#define ll long long
class Solution {
public:

    ll createPalindrome(ll num, bool odd) {
        ll x = num;
        if(odd) x /= 10;
        while(x > 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }

    bool isPalin(ll num, int base) {
        vector<int>digits;
        while(num > 0) {
            digits.push_back(num % base);
            num /= base;
        }

        int i = 0; int j = digits.size() - 1;
        while(i <= j) {
            if(digits[i] != digits[j]) return false;
            i++; j--;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        ll sum = 0ll;
        for(ll len = 1; n > 0;len *= 10) {
            for(ll i = len; n > 0 && i < len * 10;i++) {
                ll p = createPalindrome(i,true);
                if(isPalin(p,k)) {
                    sum += p;
                    n--;
                }
            }

            for(ll i = len; n > 0 && i < len * 10;i++) {
                ll p = createPalindrome(i,false);
                if(isPalin(p,k)) {
                    sum += p;
                    n--;
                }
            }
        }
        return sum;
    }
};
