#include <bits/stdc++.h>
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
    vector<string>str;
    while(t--) {
        int n,f,k; cin >> n >> f >> k;
        vt <int> v(n,0);
        for(int i = 0;i < n;i++) {
            cin >> v[i];
        }
        int check = v[f - 1];
        sort(v.begin(),v.end(),greater<int>());
        int count = 0;int big = 0;
        for(int i = 0;i < n;i++) {
            if(v[i] > check) big++;
            if(v[i] == check) count++;
        }
        if(big >= k) str.pb("NO");
        else if(big + count <= k) str.pb("YES");
        else if(big + count > k) str.pb("MAYBE");
    }
    print(str);
}

