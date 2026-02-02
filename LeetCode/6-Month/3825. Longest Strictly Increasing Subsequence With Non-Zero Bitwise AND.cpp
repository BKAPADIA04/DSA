class Solution {
public:

    int LIS(vector<int>& setBit) {
        int n = setBit.size();
        vector<int>lis;
        for(int i = 0;i < n;i++) {
            if(lis.empty() || lis.back() < setBit[i]) {
                lis.push_back(setBit[i]);
            }
            else {
                int it = lower_bound(lis.begin(),lis.end(), setBit[i]) - lis.begin();
                lis[it] = setBit[i];
            }
        }
        return lis.size();
    }

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i < 32;i++) {
            vector<int>setBit;
            for(int j = 0;j < n;j++) {
                if(nums[j] & (1 << i)) setBit.push_back(nums[j]);
            }

            ans = max(ans, LIS(setBit));
        }
        return ans;
    }
};
