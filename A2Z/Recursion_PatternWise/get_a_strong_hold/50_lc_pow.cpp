#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {

    if(n < 0) return 1/myPow(x,abs(n));

    if(n == 1) return x;

    return x * myPow(x,n - 1);    
}

int main() {
    cout << myPow(2.000,10) << endl;
}