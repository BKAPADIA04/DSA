#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    if(n > 0 && ((n & (n-1)) == 0)) return true;
    return false;
}

int main() {
    cout << isPowerOfTwo(16) << endl;
    cout << isPowerOfTwo(1073741825) << endl;
    cout << isPowerOfTwo(-2147483648) << endl;
}