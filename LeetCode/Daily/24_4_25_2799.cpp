class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>uniques;
        for(int i = 0;i < n;i++) {
            uniques[nums[i]]++;
        }
        int k = uniques.size();
        int ans = 0;

        unordered_map<int,int>freq;

        int left = 0; int right = 0;
        while(right < n) {
            freq[nums[right]]++;
            while(freq.size() == k) {
                ans += n - right;
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            right++;
        }
        return ans;
    }
};
