#define ll long long
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        ll n = nums.size();
        ll answer = 0ll;
        ll i = n - 2;
        ll last = nums[n - 1];
        for(ll i = n - 2;i >= 0;i--) {
            if(nums[i] <= last) {
                last = nums[i]; 
            }
            else {
                ll temp = nums[i] / last;
                if(nums[i] % last) temp++;
                last = nums[i] / temp;
                answer += temp - 1;
            }
        }
        return answer;
    }
};
