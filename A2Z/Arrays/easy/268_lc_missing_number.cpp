#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>nums;
    int m;cin >> m;
    for(int i = 0;i < m;i++) {
        int temp;cin >> temp;nums.push_back(temp);
    }
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;
    // int sum_vt = accumulate(nums.begin(), nums.end(), 0);
    int sum_vt = 0;
    for(int i = 0;i < n;i++) {
        sum_vt += nums[i];
    }
    return sum - sum_vt;

    // xor approach
    // int n = nums.size();
    // int xor1 = 0;int xor2 = 0;
    // for(int i = 1;i <= n;i++) {
    //     xor1 = xor1 ^ i;
    // }
    // for(int i = 0;i < n;i++) {
    //     xor2 = xor2 ^ nums[i];
    // }
    // return (xor1 ^ xor2);    
}