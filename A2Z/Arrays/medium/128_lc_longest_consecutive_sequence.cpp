#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int>u_map;int ans = INT_MIN;
        for(int i = 0;i < n;i++) {
            u_map.insert(nums[i]);
        }
        for(auto it:u_map) {
            if(u_map.find(it - 1) == u_map.end()) {
                int x = it;
                int count = 1;
                while(u_map.find(x + 1) != u_map.end()) {
                    x = x + 1;
                    count++;
                }
            ans = max(ans,count);
            }
        }
        return ans;
    }
};