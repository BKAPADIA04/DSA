#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &nums,int mid) {
    int n = nums.size();
    int days = 0;
    int sum = 0;
    for(int i = 0;i < n;i++) {
        sum += nums[i];
        if(sum > mid) {
            days++;
            sum = nums[i];
        }
        if(i == (n-1) && (sum <= mid)) {
            days++;
        }
    }
    return days;
}

int shipWithinDays(vector<int>& nums, int days) {
    int n = nums.size();
    int maxi = 0; 
    int mini = INT_MIN;
    for(int i = 0;i < n;i++) {
        maxi = maxi + nums[i]; // max = sum of all
        mini = max(mini,nums[i]); // min = max element
    }
    int low = mini;int high = maxi;
    int result = maxi; 

    while(low <= high) {
        int mid = (low + high)/2;
        if(check(nums,mid) > days) {
            low = mid + 1;
        }
        else {
            result = mid;
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    cout << shipWithinDays(nums,5) << endl;
}