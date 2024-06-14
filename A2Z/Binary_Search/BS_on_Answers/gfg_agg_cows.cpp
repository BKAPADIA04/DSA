#include <bits/stdc++.h>
using namespace std;

int check(vector<int>&nums,int n,int mid) {
    int cows = 1;
    int i = 0;
    for(int j = 1;j < n;j++) {
        if(nums[j] - nums[i] >= mid) {
            i = j;
            cows++;
        }
    }
    return cows;
}


int solve(int n, int k, vector<int> &nums) {
    // Write your code here
    // min = 1 i.e consecutive distance
    // max = max(arr) - min(arr)
    sort(nums.begin(),nums.end());
    int low = 1;
    // int high = *max_element(nums.begin(),nums.end()) - *min_element(nums.begin(),nums.end());
    int high = nums[n - 1] - nums[0];
    int result = 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int answer = check(nums,n,mid);
        if(answer >= k) {
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    vector<int>nums = {1};
    cout << solve(nums.size(),1,nums) << endl;
}
