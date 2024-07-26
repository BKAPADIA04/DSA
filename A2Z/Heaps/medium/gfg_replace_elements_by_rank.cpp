#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

vector<int> replaceWithRank(vector<int> &arr, int n) {
    vector<int>ans(n,0);
    priority_queue<p,vector<p>,greater<p>>pq;
    for(int i = 0;i < n;i++) {
        pq.push({arr[i],i});
    }
    int rank = 1;
    while(!pq.empty()) {
        int ele = pq.top().first;
        int index = pq.top().second;
        ans[index] = rank;
        pq.pop();
        if(pq.top().first != ele) rank++;
    }
    return ans;
}

int main() {
    vector<int>arr = {2, 2, 1, 6};
    vector<int>ans = replaceWithRank(arr,arr.size());
    for(int i:ans) cout << i << " " ;
    cout << endl;
}