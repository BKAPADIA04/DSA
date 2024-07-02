#include <bits/stdc++.h>
using namespace std;

void generate(vector<vector<int>>&ans,vector<int>&solve,vector<int>arr,int index,int n) {
    ans.push_back(solve);
    for(int i = index;i < n;i++) {
        if(i > index && arr[i] == arr[i-1]) continue;
        solve.push_back(arr[i]);
        generate(ans,solve,arr,i+1,n);
        solve.pop_back();
    }
}


vector<vector<int>> subsetsWithDup(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>>ans;
    vector<int>solve;
    sort(arr.begin(),arr.end());
    generate(ans,solve,arr,0,n);
    return ans;
}

int main() {
    vector<int>arr = {1,2,2};
    vector<vector<int>>ans = subsetsWithDup(arr);
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}