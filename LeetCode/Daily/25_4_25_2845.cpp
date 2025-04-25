#define ll long long
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        ll n = nums.size();
        for(ll i = 0;i < n;i++) nums[i] %= modulo;
        vector<ll>preCount;
        for(ll i = 0;i < n;i++) {
            if(preCount.size() > 0) {
                ll temp = preCount.back() + (nums[i] == k);
                preCount.push_back(temp);
            }
            else {
                ll temp = (nums[i] == k);
                preCount.push_back(temp);
            }
        }

        for(ll i = 0;i < n;i++) preCount[i] %= modulo;

        unordered_map<ll,ll>freq;
        freq[0] = 1;
        ll answer = 0;
        for(ll i = 0;i < n;i++) {
            if(freq.find((preCount[i] - k + modulo) % modulo) != freq.end()) {
                answer += freq[(preCount[i] - k + modulo) % modulo];
            }
            freq[preCount[i] % modulo]++;
        }
        return answer;
    }
};
