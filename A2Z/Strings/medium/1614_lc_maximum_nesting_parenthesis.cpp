#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int n = s.size();
    int sum = 0; int result = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == '(') sum++;
        else if(s[i] == ')') sum--;

        if(sum >= result) result = sum;
    }
    return result;
}

int main() {
    cout << maxDepth("(1+(2*3)+((8)/4))+1") << endl;
    cout << maxDepth("(1)+((2))+(((3)))") << endl;
    cout << maxDepth("()(())((()()))") << endl;
}