class Solution {
public:

    int check(vector<int>&nums,int mid) {
        int count = 0;
        for(int i = 0;i < nums.size() - 1;i++) {
            if(abs(nums[i] - nums[i+1]) <= mid) {
                count++; 
                i++;
            }
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0; int high = nums[n - 1] - nums[0];
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(nums,mid) >= p) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
