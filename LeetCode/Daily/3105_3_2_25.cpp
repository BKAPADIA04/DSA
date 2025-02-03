class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // int n = nums.size();
        // int j = 0;
        // int i = 1; int ans = 1;
        // while(i < n) {
        //     if(nums[i] <= nums[i-1]) {
        //         ans = max(ans,i - j);
        //         j = i;
        //         // while(j > 0 && nums[j-1] < nums[i]) j--;
        //     }
        //     i++;
        // }
        // ans = max(ans, i - j);


        // j = 0;
        // i = 1;
        // while(i < n) {
        //     if(nums[i] >= nums[i-1]) {
        //         ans = max(ans,i - j);
        //         j = i;
        //         // while(j > 0 && nums[j-1] > nums[i]) j--;
        //     }
        //     i++;
        // }
        // ans = max(ans, i - j);
        // return ans;

        int n = nums.size(); int inc = 1,dec = 1; int ans = 1;
        for(int i = 1;i < n;i++) {
            if(nums[i] > nums[i-1]) {
                inc++; dec = 1;
            }
            else if(nums[i] < nums[i-1]) {
                dec++; inc = 1;
            }
            else {
                inc = 1; dec = 1;
            }
            ans = max(ans,max(inc,dec));
        }
        return ans;
    }
};
