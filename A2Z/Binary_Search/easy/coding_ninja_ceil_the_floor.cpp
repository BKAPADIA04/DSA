#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
    int low = 0;
    int high = n - 1;
    int floor = -1;int ceil = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(a[mid] == x) { floor = a[mid]; ceil = a[mid]; high = mid - 1; low = mid + 1;}
        else if(a[mid] > x) { ceil = a[mid]; high = mid - 1;}
        else { floor = a[mid]; low = mid + 1;}
    }
    pair<int,int>p = {floor,ceil};
    return p;
}

int main() {
    vector<int>nums = {3,4,4,7,8,10};
    pair<int,int>ans = getFloorAndCeil(nums,nums.size(),11);
    cout << ans.first << " " << ans.second << endl;
}