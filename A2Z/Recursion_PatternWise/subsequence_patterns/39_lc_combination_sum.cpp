#include <bits/stdc++.h>
using namespace std;

void generate(vector<vector<int>>&ans,vector<int>& candidates,vector<int>&store,int target,int i,int n) {
    if(i == n) {
        if(target == 0) {
            ans.push_back(store);
        }
        return;
    }
    // Pick
    if(candidates[i] <= target) {
        store.push_back(candidates[i]);
        generate(ans,candidates,store,target - candidates[i],i,n);
        store.pop_back();
    }
    // Non-Pick
    generate(ans,candidates,store,target,i+1,n);
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>store;
    generate(ans,candidates,store,target,0,candidates.size());
    return ans;
}

int main() {
    vector<int>candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>>ans = combinationSum(candidates,target);
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}