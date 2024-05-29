#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>v(n,0);int sum = 0;int ans = 0;
        for(int i = 0;i < n;i++) {
            cin >> v[i];sum += v[i];
        }

        if(sum % 2 == 0) {cout << n << endl;}
        else {
            for (int i = 0; i < n; i++) {
            if (v[i] % 2 == 1)
                ans = max(ans, max(n - i - 1, i));
            }
            cout << ans << endl;
        }
    }
}