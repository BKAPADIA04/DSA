#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int>pq;
    int n = nums.size();
    for(int i = 0;i < n;i++) pq.push(nums[i]);
    for(int i = 0;i < k-1;i++) pq.pop();

    return pq.top();
}

int main() {
    vector<int>nums = {3,2,1,5,6,4};
    int k = 2;
    cout << findKthLargest(nums,k) << endl;
}