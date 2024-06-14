#include <bits/stdc++.h>
using namespace std;

int check(vector<int>& nums,long long mid) {
    int n = nums.size();
    int count = 1;
    long long sum = 0;
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

int findLargestMinDistance(vector<int> &nums, int k)
{
    //    Write your code here.
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
    vector<int>nums = {10,20,30,40};
    cout << findLargestMinDistance(nums,2) << endl;
}