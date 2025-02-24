class Solution {
public:

    int numRescueBoats(vector<int>& nums, int limit) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0; int right = nums.size()-1; int count = 0;
        while(left <= right) {
            if(left != right && nums[left] + nums[right] <= limit) {
                left++; right--;
            }
            else if(left == right && nums[left] <= limit) {
                left++; right--;
            }
            else {
                right--;
            }
            count++;
        }
        return count;
    }
};
