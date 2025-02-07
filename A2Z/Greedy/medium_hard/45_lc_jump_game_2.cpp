#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    pair<int,int>longest = {0,nums[0]};
    for(int i = 1;i < n;i++) {
        if(nums[i] + i > longest.second) {
            longest.first = i;
            longest.second = nums[i] + i;

        }
        if(longest.second >= n-1) return longest.first + 1;
    }        
    return 0;
}

int main() {
    vector<int>nums = {2,3,0,1,4};
    cout << jump(nums) << endl;
}