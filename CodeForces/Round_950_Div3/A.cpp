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
    while(t--) {
        int n,m; cin >> n >> m;
        string str; cin >> str;
        vector<int>count(7,0);
        for(int i = 0;i < n;i++) {
            if(str[i] == 'A') count[0]++;
            if(str[i] == 'B') count[1]++;
            if(str[i] == 'C') count[2]++;
            if(str[i] == 'D') count[3]++;
            if(str[i] == 'E') count[4]++;
            if(str[i] == 'F') count[5]++;
            if(str[i] == 'G') count[6]++;
        }
        int ans = 0;
        for(int i = 0;i < 7;i++) {
            if(count[i] == 0) ans += m;
            else if(count[i] < m) ans += (m - count[i]);
        }
        cout << ans << endl;
    }
}