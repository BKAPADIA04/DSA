#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int>ans;
    map<int,int>freq_map;
    for(int i = 0;i < nums.size();i++) freq_map[nums[i]]++;

    priority_queue<pair<int,int>>pq;
    for(auto it:freq_map) pq.push({it.second,it.first});
    while(k--) {
        int top = pq.top().second;
        ans.push_back(top);
        pq.pop();
    }
    return ans;
}

int main() {
    vector<int>nums = {1,1,1,2,2,3,3};
    int k = 2;
    vector<int>ans = topKFrequent(nums,k);
    for(int i:ans) cout << i << " ";
    cout << endl;
}