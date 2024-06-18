#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    int n = s.size();
    int m = t.size();
    if(n != m) return false;
    set<char>set1; set<char>set2;
    for(int i = 0;i < n;i++) {
        set1.insert(s[i]);
        set2.insert(t[i]);
    }

    if(set1.size() == set2.size()) return true;
    return false;
}

int main() {
    cout << isIsomorphic("egg","add") << endl;
}