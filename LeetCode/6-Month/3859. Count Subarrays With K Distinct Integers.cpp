#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        ll n = nums.size();
        ll r1 = -1ll; ll r2 = -1ll;
        // r2 -> < k + 1 distinct elements
        // r1 -> from this point onwards, atleast m times occurence of k elements

        ll answer = 0ll;
        unordered_map<ll,ll>mp1,mp2; ll cnt = 0ll;
        for(ll i = 0;i < n;i++) {
            while(r2 < n && mp2.size() < k + 1) {
                r2++;
                if(r2 < n) mp2[nums[r2]]++;
            }

            while(r1 < n && cnt < k) {
                r1++;
                if(r1 < n) {
                    mp1[nums[r1]]++;
                    if(mp1[nums[r1]] == m) cnt++;
                }
            }

            if(r2 > r1) answer += r2 - r1;

            mp2[nums[i]]--;
            if(mp2[nums[i]] == 0) mp2.erase(nums[i]);

            mp1[nums[i]]--;
            if(mp1[nums[i]] == (m-1)) cnt--;
        }   

        return answer;
    }
};
