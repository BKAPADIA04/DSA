class Solution {
public:
    
    long long numberOfSubsequences(vector<int>& nums) {
        // long long mod = 1e18;
        int n = nums.size();
        unordered_map<string,int>freq;
        long long ans = 0ll;
        for(int r = 4; r < n-2;r++) {
            int q = r - 2;
            for(int p = 0; p <= q-2;p++) {
                int gcd = __gcd(nums[p],nums[q]);
                string temp = to_string(nums[p]/gcd) + "-" + to_string(nums[q]/gcd);
                freq[temp]++; 
            }

            for(int s = r+2;s < n;s++) {
                int gcd = __gcd(nums[s],nums[r]);
                string temp = to_string(nums[s]/gcd) + "-" + to_string(nums[r]/gcd);
                ans = (ans + freq[temp]);
            }
        }
        return ans ;
    }
};