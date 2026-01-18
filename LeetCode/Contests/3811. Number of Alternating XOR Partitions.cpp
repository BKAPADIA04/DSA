#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;
    ll n;
    ll t1; ll t2;
    vector<int>nums;
    vector<ll>preXor;

    unordered_map<long long, int> memo;

    ll check(ll i, ll option, ll currXor) {
        if(i >= n) {
            if((!option && currXor == t1) || (option && currXor == t2)) return 1ll;
            return 0ll;
        }

        long long stateKey =((long long)i << 32) |((long long)currXor << 1) | option;

        if (memo.count(stateKey))
            return memo[stateKey];

        long long ways = 0;

        // Option 1: Stop current segment & switch turn
        if ((!option && currXor == t1) ||
            (option && currXor == t2)) {
            ways += check(i + 1,!option,nums[i]);
        }

        // Option 2: Continue XOR with same num
        ways += check(i + 1,option,currXor ^ nums[i]);

        return memo[stateKey] = ways % mod;
    }
    
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        n = nums.size();
        t1 = target1;
        t2 = target2;
        this->nums = nums;
        // return check(1,0, nums[0]);
        preXor = vector<ll>(n,0);
        for(int i = 0;i < n;i++) preXor[i] = nums[i] ^ (i ? preXor[i-1] : 0);

        unordered_map<int,ll>mp1,mp2;
        // mp1 = count of prefix XORs 'x' that just completed target1
        // mp2 = count of prefix XORs 'x' that just completed target2
        ll count1 = 0ll; // Ways ending in target1
        ll count2 = 0ll; // Ways ending in target2

        mp2[0] = 1ll;
        ll prefixXor = 0ll;

        for(ll i = 0;i < n;i++) {
            prefixXor ^= nums[i];

            int preXorT1 = prefixXor ^ target1;
            count1 = mp2.count(preXorT1) ? mp2[preXorT1] : 0;

            int preXorT2 = prefixXor ^ target2;
            count2 = mp1.count(preXorT2) ? mp1[preXorT2] : 0;

            mp1[prefixXor] = (mp1[prefixXor] + count1) % mod;
            mp2[prefixXor] = (mp2[prefixXor] + count2) % mod;
        }   

        return (count1 + count2) % mod;
    }
};
