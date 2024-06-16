#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > nums, int n, int m) {
    // code here
    int answer = INT_MAX;int index = -1;
    for(int i = 0;i < n;i++) {
        int one_index = lower_bound(nums[i].begin(),nums[i].end(),1) - nums[i].begin();
        // cout << one_index << endl;
        if((one_index < m)&&(one_index < answer))
        {
            answer = one_index;
            index = i;
        }
    }
    return index;
}

int main() {
    vector<vector<int> > nums = {{0, 0}, {1, 1}};
    int n = nums.size();
    int m = nums[0].size();
    cout << rowWithMax1s(nums,n,m) << endl;
}