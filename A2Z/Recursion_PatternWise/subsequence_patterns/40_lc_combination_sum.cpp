#include <bits/stdc++.h>
using namespace std;

void generate(vector<vector<int>>&ans,vector<int>&solve,vector<int>& candidates,int target,int i,int n){
    if(target == 0) {
        ans.push_back(solve);
        return;
    }

    for(int index = i;index < n;index++) {
        if(index > i && candidates[index] == candidates[index-1]) continue;
        if(candidates[index] > target) break;
        solve.push_back(candidates[index]);
        generate(ans,solve,candidates,target-candidates[index],index+1,n);
        solve.pop_back();
    }
}   


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>solve;
    sort(candidates.begin(),candidates.end());
    generate(ans,solve,candidates,target,0,candidates.size());
    return ans;
}


int main() {
    vector<int>candidates = {2,5,2,1,2};
    int target = 5;
    vector<vector<int>>ans = combinationSum2(candidates,target);
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}