#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int p_index = 0; int n_index = 1;
        vector<int>ans(n,0);
        for(int i = 0;i < n;i++) {
            if(nums[i] > 0) {
                ans[p_index] = nums[i];
                p_index += 2;
            }
            else {
                ans[n_index] = nums[i];
                n_index += 2;
            }
        }
        return ans;
    }
};