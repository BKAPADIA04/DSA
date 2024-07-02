#include <bits/stdc++.h>
using namespace std;

void generate(vector<int>&ans,vector<int>&solve,vector<int>arr,int i,int n,int sum) {
    if(i == n) {
        ans.push_back(sum);return;
    }
    solve.push_back(arr[i]);
    generate(ans,solve,arr,i+1,n,sum + arr[i]);
    solve.pop_back();
    generate(ans,solve,arr,i+1,n,sum);
}


vector<int> subsetSums(vector<int> arr, int n) {
    vector<int>ans;
    vector<int>solve;
    generate(ans,solve,arr,0,n,0);
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<int>arr = {5,2,1};
    vector<int>ans = subsetSums(arr,arr.size());
    for(auto i:ans) cout << i << " ";
    cout << endl;
}