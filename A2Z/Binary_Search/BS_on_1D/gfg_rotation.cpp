#include <bits/stdc++.h>
using namespace std;

int findKRotation(int nums[], int n) {
    // code here
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[low] <= nums[mid]) {
            if(nums[low] < ans) {
                ans = nums[low];
                index = low;
            }
            low = mid + 1;
        } 
        else {
            if(nums[mid] < ans) {
                ans = nums[low];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int main() {
    int nums[] = {66,67 ,7, 10, 14, 19, 27, 33, 36, 40, 44, 54, 60};
    int n = sizeof(nums) / sizeof(int);
    cout << findKRotation(nums,n) << endl;
}