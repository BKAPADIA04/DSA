#include <bits/stdc++.h>
#include <iostream>
using namespace std; 
#define vt vector
#define pb push_back
#define ll long long
#define ld long double
#define ar array
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }

string bruteForce(int n,vector<int>nums) {
    vector<int>freq(55,-1);
    for(int i = 1; i <= n;i++) freq[i] = 0;
    for(int i = 1; i <= n;i++) ++freq[nums[i-1]];
    
    for(int i = 1; i <= n;i++) {
        if(freq[i] % 2 == 1) return "YES";
    }
    return "NO";
}


int main() {
    int t; cin >> t;
    vt<string>ans;
    while(t--) {
        int n; cin >> n;
        vt<int>nums(n,-1);
        for(int i = 0;i < n;i++) {
            cin >> nums[i];
        }
        ans.pb(bruteForce(n,nums));
    }
    print(ans);
}