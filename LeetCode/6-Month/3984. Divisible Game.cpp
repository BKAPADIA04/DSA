#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;

    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        st.insert(2);
        for(int i = 0;i < n;i++) {
            int num = nums[i];
            for(int j = 2;j * j <= num;j++) {
                if((num % j)== 0) { st.insert(j); while(num % j == 0) num/= j;}
            }
            if(num > 1) st.insert(num);
        }

        ll ans = LLONG_MIN; ll div = 2;
        for(auto it : st) {
            ll currSum = 0ll; ll maxi = LLONG_MIN;
            for(int num : nums) {
                ll val = (num % it) ? -num : num;
                currSum = max(val, currSum + val);
                maxi = max(maxi, currSum);
            }
            if(maxi > ans) {
                ans = maxi; 
                div = it;
            }
            else if(maxi == ans && it < div) div = it;
        }
        ans = (ans % mod + mod) % mod;
        return (ans * div)% mod;
    }
};
