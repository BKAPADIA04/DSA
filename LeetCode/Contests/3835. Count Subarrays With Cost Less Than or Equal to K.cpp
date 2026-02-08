#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        deque<int>mini,maxi;
        ll answer = 0ll;
        int left = 0;

        for(int right = 0; right < n;right++) {
            while(!mini.empty() && nums[mini.back()] > nums[right]) mini.pop_back();
            mini.push_back(right);
            while(!maxi.empty() && nums[maxi.back()] < nums[right]) maxi.pop_back();
            maxi.push_back(right);
            
            while((ll)((ll)nums[maxi.front()] - (ll)nums[mini.front()]) * (ll)(right - left + 1) > k) {
                if(mini.front() == left) mini.pop_front();
                if(maxi.front() == left) maxi.pop_front();
                left++;
            }

            answer += right - left + 1;
        }

        return answer;
    }
};
