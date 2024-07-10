#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> answer;
    int n = nums.size();
    int subsets = (1 << n);

    for(int i = 0;i < subsets;i++) {
        vector<int>sub_subsets;
        for(int j = 0;j < n;j++) {
            if(i & (1 << j)) sub_subsets.push_back(nums[j]);
        }
        answer.push_back(sub_subsets);
    }
    return answer;
}

int main() {
    vector<int>nums = {1,2,3};
    vector<vector<int>> answer = subsets(nums);
    for(auto i : answer) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}