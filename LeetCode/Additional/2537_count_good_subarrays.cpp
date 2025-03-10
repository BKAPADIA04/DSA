#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ll n = nums.size();
        unordered_map<ll,ll>freq;
        ll left = 0ll;
        ll right = 0ll;
        ll pairs = 0ll;
        ll answer = 0ll;

        while(right < n) {
            if(freq.find(nums[right]) != freq.end()) {
                pairs += freq[nums[right]];
            }
            freq[nums[right]]++;
            
            while(pairs >= k) {
                answer += (n - right);
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                // if(freq[nums[left]] == 1) pairs--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            right++;
        }
        return answer;
    }
};
