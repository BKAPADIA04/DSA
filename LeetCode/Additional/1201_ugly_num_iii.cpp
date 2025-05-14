#define ll long long
class Solution {
public:

    ll gcd(ll a, ll b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    ll lcm(ll a,ll b) {
        return (a * b) / gcd(a,b);
    }

    int count(ll num, ll a, ll b, ll c) {
        ll ans = num/a + num/b + num/c - num/lcm(a,b) - num/lcm(b,c) - num/lcm(a,c) + num/lcm(a,lcm(b,c));
        return (int)ans;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        int ans = 2 * 1e9;
        int left = 1; int right = 2 * 1e9;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(count(mid,a,b,c) >= n) {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
