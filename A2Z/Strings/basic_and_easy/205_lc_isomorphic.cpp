#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    int n = s.size();
    int m = t.size();
    if(n != m) return false;
    unordered_map <char,char> u_map;
    vector<int>characters(256,-1);
    for(int i = 0;i < n;i++) {
        if(u_map.find(s[i]) == u_map.end() && characters[t[i]] == -1) {
            u_map[s[i]] = t[i];
            characters[t[i]] = 1;
        }
        else {
            if(u_map[s[i]] != t[i]) return false;
        }
    }
    return true;
}

int main() {
    cout << isIsomorphic("pijthbsfy","fvladzpbf") << endl;
}