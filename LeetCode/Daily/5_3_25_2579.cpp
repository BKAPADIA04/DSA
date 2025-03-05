#define ll long long
class Solution {
public:
    long long coloredCells(int n) {
        ll sum = 0;
        ll i = 1;
        while(2*n - i > 0) {
            if(i == 1) sum += (2 * (ll)n - i);
            else sum += (ll)2 * (((ll)2 * (ll)n) - i);
            // cout << i << " " << sum << endl;
            i += 2;
        }
        // return sum;



        ll ans = (ll)((ll)2 * (ll)((ll)n * (ll)n)) - 2 * n + 1;
        return ans;
    }
};
