#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int>m;
        for(int i = 0;i < n;i++) {
            int rem = target - nums[i];
            if(m.find(rem) != m.end()) {
                return {m[rem],i};
            }
            m[nums[i]] = i;
        }
        return {-1,-1};
    }
};