#include <bits/stdc++.h>
using namespace std;


int atoiNumber(string s,int * isNegative) {
    int n = s.size();
    if(n == 1) return isdigit(s[0]) ? s[0] - '0' : (*isNegative ? 1 : -1);
    if(s[0] == '-') { *isNegative = 1; return -atoiNumber(s.substr(1),isNegative);}
    for(int i = 0;i < n;i++) {
        if(!isdigit(s[i])) {return *isNegative ? 1 : -1;}
    }
    int answer = 10 * atoiNumber(s.substr(0,n - 1),isNegative) + (s[n-1] - 48);
    return answer;
}



int main() {
    int isNegative = 0;
    cout << atoiNumber("x",&isNegative) << endl;
    cout << isdigit('x') << endl;
}