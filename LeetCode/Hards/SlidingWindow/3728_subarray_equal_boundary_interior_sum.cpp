#define ll long long
class Solution {
public:
    long long countStableSubarrays(vector<int>& nums) {
        ll n = nums.size();
        map<pair<ll,ll>,ll>mp;
        ll preSum = 0ll;

        if(n == 0 || n == 1 || n == 2) return 0;

        ll answer = 0ll;
        
        for(ll i = 1;i < n;i++) {
            preSum += nums[i];
            pair<ll,ll>req = {nums[i], preSum - 2 * nums[i]};
            if(mp.find(req) != mp.end()) {
                answer += mp[req];
            }
            
            mp[{nums[i-1],preSum-nums[i]}]++; 
        }

        for(auto it : mp) {
            cout << it.first.first << " " << it.first.second << " " << it.second << endl;
        }

        return answer;
    }
};
