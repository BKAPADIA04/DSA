#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int count = 1; int start = 0; int maxLen = 1;
  for(int i = 1;i < n;i++) {
    if(s[i] == s[i - 1]) {
      count++;
      if(count == 3) {
        start = i - 1;
        count = 2;
      }
    }
    else {
      count = 1;
    }
    
    maxLen = max(maxLen,i - start + 1);
  }
  cout << maxLen << endl;
  return 0;
}
