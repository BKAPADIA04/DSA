#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();
    int count = 0;
    vector<int>lastSeen(3,-1);
    for(int i = 0;i < n;i++) {
        lastSeen[s[i] - 'a'] = i;
        if((lastSeen[0] != -1) && (lastSeen[1] != -1) && (lastSeen[2] != -1)) {
            count += 1 + min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
        }
    }        
    return count;
}

int main() {
    cout << numberOfSubstrings("abcabc") << endl;
}