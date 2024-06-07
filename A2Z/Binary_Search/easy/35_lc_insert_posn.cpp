#include <bits/stdc++.h>
using namespace std;

int searchInsert_LowerBound(vector<int>& nums, int target) {
    int n = nums.size();
    int lower = lower_bound(nums.begin(),nums.end(),target) - nums.begin() - 1;
    cout << lower << endl;
    if(lower == -1) return 0;
    if(nums[lower] == target) return lower;
    return lower + 1;
}

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;int high = n - 1;
    int index = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) { index = mid; high = mid - 1;}
        else low = mid + 1;
    }
    return index;

    // or
    // while (low <= high) {
    //     int mid = (low + high) / 2;
    //     // maybe an answer
    //     if (arr[mid] >= x) {
    //         ans = mid;
    //         //look for smaller index on the left
    //         high = mid - 1;
    //     }
    //     else {
    //         low = mid + 1; // look on the right
    //     }
    // }
    // return ans;
}


int main() {
    vector<int>nums = {1,3,5,6};
    int target = 7;
    cout << searchInsert(nums,target) << endl;
}