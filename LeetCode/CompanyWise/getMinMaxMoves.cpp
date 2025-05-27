#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int>nums;
    unordered_map<int,int>umap;
    int mini = INT_MAX; int miniIndex = -1; int maxi = INT_MIN; int maxiIndex = -1;
    for(int i = 0;i < n;i++) {
        int ele; cin >> ele; nums.push_back(ele);
        umap[ele] = i;
        if(ele > maxi) {
            maxi = ele; maxiIndex = i;
        }
        if(ele < mini) {
            mini = ele; miniIndex = i;
        }
    }

    int ans = 0;
    int temp = miniIndex;
    while(temp != 0) {
        swap(umap[nums[temp]],umap[nums[temp-1]]);
        temp--;
        ans++;
    }

    temp = umap[maxi];
    while(temp != n - 1) {
        swap(umap[nums[temp]],umap[nums[temp+1]]);
        temp++;
        ans++;
    }
    
    cout << ans << endl;
}
