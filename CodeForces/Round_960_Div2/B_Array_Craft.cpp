#include <bits/stdc++.h>
#include <iostream>
using namespace std; 
#define vt vector
#define pb push_back
#define ll long long
#define ld long double
#define ar array
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,x,y; cin >> n >> x >> y;
        vector<int>ans(n+1,1);
        for(int i = y - 1;i >= 1;i-=2) ans[i] = -1;
        for(int i = x + 1;i <= n;i+=2) ans[i] = -1;
        for(int i = 1;i <= n;i++) cout << ans[i] << " ";
        cout << endl;
    }
}
