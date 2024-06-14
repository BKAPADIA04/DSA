#include <bits/stdc++.h>
using namespace std;

int check(vector<int>& nums,int mid) {
    int n = nums.size();
    int count = 1;
    int sum = 0;
    for(int i = 0;i < n;i++) {
        if(sum + nums[i] <= mid) {
            sum += nums[i];
        }
        else {
            count++;
            sum = nums[i];
        }
    }
    return count;
}

int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    int result = low;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(nums,mid) <= k) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int>nums = {7,2,5,10,8};
    cout << splitArray(nums,2) << endl;
}