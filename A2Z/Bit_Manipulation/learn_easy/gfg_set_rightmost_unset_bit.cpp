#include <bits/stdc++.h>
using namespace std;

int setBit(int n) {
    return (n | (n+1));
}

int main() {
    cout << setBit(6) << endl;
    cout << setBit(15) << endl;
    cout << setBit(1) << endl;
    cout << setBit(1e9) << endl;
}