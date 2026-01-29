#define ll long long
class Solution {
public:
    bool judgeSquareSum(int c) {
        ll left = 0ll;
        ll right = (ll)sqrt(c);

        while(left <= right) {
            ll sum = left * left + right * right;
            if(sum == (ll)c) return true;
            else if(sum > (ll)c) right--;
            else left++;
        }
        return false;
    }
};
