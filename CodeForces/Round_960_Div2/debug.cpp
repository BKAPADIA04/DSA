#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    // constraints
    srand(time(NULL));
    // t -> 1000
    // n-> 2 to 50
    // a[i] -> 1 to n
    int t = rand() % 5 + 1;
    cout << t << endl;
    while(t--) {
        int n = rand() % 10 + 1;
        cout << n << endl;
        for(int i = 0;i < n;i++) {
            cout << rand() % n + 1 << " ";
        }
        cout << endl;
    }
}