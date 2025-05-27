#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    unordered_map<char,int>umap;
    int n = str.size();
    umap[str[n - 1]]++;
    int ans = 0;
    for(int j = n - 2;j >= 0;j--) {
        ans += (n - j - 1);
        ans -= umap[str[j]];
        umap[str[j]]++;
    }
    cout << ans << endl;
}
