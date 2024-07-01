#include <bits/stdc++.h>
using namespace std;

void generateSubsets(vector<vector<int>> &generate,vector<int>& nums,int i,int n) {
    if(i == n) return;
    int ele = nums[i];
    for(int j = 0;j < generate.size();j++) {
        vector<int>inner = generate[j];
        if(count(inner.begin(),inner.end(),ele) == 0) {
            inner.push_back(ele);
            generate.push_back(inner);
        }
    }
    generateSubsets(generate,nums,i+1,n);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>generate;
    generate.push_back({});
    generateSubsets(generate,nums,0,nums.size());
    return generate;  
}

// or
void solve(int i, string s, string &f) {
	if (i == s.length()) {
		cout << f << " ";
		return;
	}
	//picking 
	f = f + s[i];
	solve(i + 1, s,  f);
	//poping out while backtracking
	f.pop_back();
	solve(i + 1, s,  f);
}

int main() {
    vector<int>nums = {1,2,3};
    vector<vector<int>>answer = subsets(nums);
    for(auto i:answer) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}