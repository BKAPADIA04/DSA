#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_ = 0;
        for(int i = 0;i < n;i++) {
            xor_ = xor_ ^ nums[i];
        }
        return xor_;
    }
};