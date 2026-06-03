#define ll long long
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        ll n = nums.size();
        ll pos = 0ll; bool isZero = false;
        vector<ll>neg; ll negProd = 0ll;
        for(ll i = 0;i < n;i++) {
            if(nums[i] == 0) isZero = true;
            else if(nums[i] > 0) {
                if(pos == 0ll) pos = nums[i];
                else pos = pos * nums[i] * 1ll;
            }
            else {
                neg.push_back(nums[i]);
                if(negProd == 0ll) negProd = nums[i];
                else negProd = negProd * nums[i] * 1ll;
            }   
        }

        sort(neg.begin(), neg.end());
        ll negSz = neg.size();
        if((negSz & 1) && negSz > 1) negProd /= neg[negSz - 1];

        // cout << pos << " " << negProd << endl;


        if(pos != 0ll && negProd > 0ll) return (ll)pos * (ll)negProd;

        if(pos != 0ll && negProd <= 0ll) return pos;

        if(pos == 0ll) {
            if(negSz == 1 && isZero) return 0ll;
        }

        return negProd;
    }
};
