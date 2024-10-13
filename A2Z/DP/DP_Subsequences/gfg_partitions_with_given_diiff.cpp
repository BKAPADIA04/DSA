class Solution {
public:
    long long min_diff = INT_MAX;
    
    void solve(vector<int>& nums, int index, long long arr1_sum,
            long long arr2_sum, int arr1_length, int arr2_length)
    {
        if (arr1_length > nums.size() / 2
            || arr2_length > nums.size() / 2) {
            return;
        }
    
        if (index == nums.size()) {
            long long diff = abs(arr1_sum - arr2_sum);
            min_diff = min(min_diff, diff);
            return;
        }
    
        solve(nums, index + 1, arr1_sum + nums[index], arr2_sum,
            arr1_length + 1, arr2_length);
        solve(nums, index + 1, arr1_sum, arr2_sum + nums[index],
            arr1_length, arr2_length + 1);
    }
    int minimumDifference(vector<int>& arr) {
        solve(arr, 0, 0, 0, 0, 0);
        return min_diff;
    }
};