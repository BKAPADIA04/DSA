#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while(low <= high) {
        int mid = (low + high) / 2;
        // left part is sorted ... so most left is the smallest
        if(nums[low] <= nums[mid]) {
            ans = min(ans,nums[low]);
            low = mid + 1;
        } 
        // right part is sorted ... so mid is the smallest
        else {
            ans = min(ans,nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

// or

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}