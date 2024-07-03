#include <bits/stdc++.h>
using namespace std;

void generate(vector<vector<int>>&ans,vector<int>& nums,vector<int>&store,int target,int i,int k,int n) {
    if(k == 0) {
        if(target == 0) {
            ans.push_back(store);
        }
        return;
    }
    
    if(i == n) return;

    if(nums[i] <= target) {
        store.push_back(nums[i]);
        generate(ans,nums,store,target - nums[i],i+1,k-1,n);
        store.pop_back();
    }
    generate(ans,nums,store,target,i+1,k,n);
}


vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>>ans;
    vector<int>store;
    vector<int>nums;
    for(int i = 1;i <= min(9,n);i++) nums.push_back(i);
    generate(ans,nums,store,n,0,k,nums.size());
    return ans;
}

int main() {
    vector<vector<int>>ans = combinationSum3(2,18);
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}