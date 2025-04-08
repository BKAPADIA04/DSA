class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // int ans = 0;
        // for(int i = 1;i < n;i++) {
        //     if(nums[i] <= nums[i-1]) {
        //         int increaseBy = nums[i-1] - nums[i] + 1;
        //         ans += increaseBy;
        //         nums[i] += increaseBy;
        //     }
        // }
        // return ans;

        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>countArray(maxi + n + 1,0);
        for(int i = 0;i < n;i++) {
            countArray[nums[i]]++;
        }
        
        int ans = 0;
        for(int i = 0;i < countArray.size();i++) {
            if(countArray[i] > 1) {
                countArray[i+1] += countArray[i] - 1;
                ans += countArray[i] - 1;
            }
        }
        return ans;
    }
};
