#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    vector<int>ans;
    int n = arr[0].size();
    priority_queue<p,vector<p>,greater<p>>pq;
    for(int i = 0;i < k;i++) {
        pq.push({arr[i][0],i});
    }
    vector<int>ks(k,0);
    int count = 0;
    while(count <= (k*k)) {
        if(pq.empty()) break;
        int ele = pq.top().first;
        int i = pq.top().second;
        ans.push_back(ele);
        pq.pop();
        count++;
        if(ks[i] + 1 < n) {
            pq.push({arr[i][++ks[i]],i});
        }
    }
    return ans;
}

int main() {
    vector<vector<int>>arr = {{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}};
    vector<int>ans = mergeKArrays(arr,4);
    for(int i:ans) cout << i << " ";
    cout << endl;
}