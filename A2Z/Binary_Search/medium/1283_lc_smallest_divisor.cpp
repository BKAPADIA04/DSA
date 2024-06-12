#include <bits/stdc++.h>
using namespace std;
int answer(vector<int>&nums,int divisor) {
    int n = nums.size();
    int sum = 0;
    for(int i = 0;i < n;i++) {
        sum += ceil((nums[i] + divisor - 1)/divisor);
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    int maxi = INT_MIN; 
    for(int i = 0;i < n;i++) {
        maxi = max(maxi,nums[i]);
    }
    int low = 1;
    int high = maxi;
    int ans = maxi;
    while(low <= high) {
        int mid = (low + high) / 2;
        int result = answer(nums,mid);
        if(result > threshold) { low = mid + 1;}
        else {ans = mid;high = mid - 1;}
    }
    return ans;
}

int main() {
    vector<int>nums = {1,2,5,9};
    cout << smallestDivisor(nums,6) << endl;
}