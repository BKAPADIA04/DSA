#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return;
        k = k % n;
        // Space - O(n)
        // vector<int>temp(n,0);
        // for(int i=0;i<n;i++) {
        //     temp[(i + k) % n] = nums[i];
        // }
        // for(int i=0;i<n;i++) {
        //     nums[i] = temp[i];
        // }

        // Try with Space - O(1)
        reverse(nums.begin() + n - k,nums.end());
        reverse(nums.begin(),nums.begin() + n - k);
        reverse(nums.begin(),nums.end());
    }
};