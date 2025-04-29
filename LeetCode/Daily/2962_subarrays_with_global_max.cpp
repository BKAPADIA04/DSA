#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int left = 0;
        int right = 0;
        ll answer = 0ll;
        int freqMax = 0;
        while(right < n) {
            if(nums[right] == maxi) freqMax++;

            while(freqMax >= k) {
                answer += (n - right);
                if(nums[left] == maxi) freqMax--;
                left++;
            }
            right++;
        }
        return answer;
    }
};
