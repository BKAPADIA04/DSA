#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0) return -1;
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        // Either side of the mid is already sorted
        // Left sorted
        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && target <= nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
        else {
            if(nums[mid] <= target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int>nums = {4,5,6,7,0,1,2};
    cout << search(nums,3) << endl;
}