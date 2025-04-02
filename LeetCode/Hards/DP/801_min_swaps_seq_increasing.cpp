class Solution {
public:

    vector<vector<int>>dp;

    int check(int index,int swapped, vector<int>&nums1,vector<int>&nums2) {
        if(index >= nums1.size()) return 0;

        if(dp[index][swapped] != -1) return dp[index][swapped];

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if(swapped) swap(prev1, prev2);
        int ans = INT_MAX;
        if(nums1[index] > prev1 && nums2[index] > prev2) {
            ans = check(index + 1, 0, nums1,nums2);
        }
        if(nums1[index] > prev2 && nums2[index] > prev1) {
            ans = min(ans,1 + check(index + 1, 1, nums1,nums2));
        }

        return dp[index][swapped] = ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n = nums1.size();
        dp = vector<vector<int>>(n,vector<int>(2,-1));

        return check(1,0,nums1,nums2);
    }
};
