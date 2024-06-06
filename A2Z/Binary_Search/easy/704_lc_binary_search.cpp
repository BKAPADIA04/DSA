#include <bits/stdc++.h>
using namespace std;

// Iterative
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0; int high = n - 1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

// Recursive

int binarySearch(vector<int>& nums, int target,int low,int high) {
    if(low > high) return -1;
    int mid = low + (high - low) / 2;
    if(nums[mid] == target) return mid;
    if(nums[mid] > target) return binarySearch(nums,target,low,mid - 1);
    else return binarySearch(nums,target,mid + 1,high);
}

int search_recursive(vector<int>& nums, int target) {
    return binarySearch(nums,target,0,nums.size() - 1);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 10;
    int ind = search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    cout << search_recursive(a, target) << endl;
    return 0;
}