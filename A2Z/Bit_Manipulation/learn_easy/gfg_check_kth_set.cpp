#include <bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k) {
    // Your code here
    // It can be a one liner logic!! Think of it!!
    return (n & (1 << k));
}

int main() {
    cout << checkKthBit(4,0) << endl;
}