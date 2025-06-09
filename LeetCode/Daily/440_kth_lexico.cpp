#define ll long long
class Solution {
public:

    int count(ll n, ll curr, ll next) {
        ll ans = 0ll;
        while(curr <= n) {
            ans += (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, (ll)n+1);
        }
        return (int)ans;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;

        while(k > 0) {
            int temp = count(n, curr, curr + 1);
            if(temp <= k) {
                curr = (ll)curr + 1;
                k -= temp;
            }
            else {
                curr = (ll)curr * 10;
                k -= 1;
            }
        }
        return curr;
    }
};
