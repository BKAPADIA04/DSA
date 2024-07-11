#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    
    bool sign = false; // positive
    if((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0)) sign = true; // negative

    long num = abs(dividend);
    long deno = abs(divisor);
    if(num < deno) return 0;
    long quotient = 0;

    while(num >= deno) {
        int counter = 0;
        while(num >= (deno << (counter+1))) counter++;
        quotient += (1 << counter);
        num = num - (deno << counter);
    }

    if(quotient == (1 << 31) && sign) return INT_MIN;
    if(quotient == (1 << 31) && !sign) return INT_MAX;

    return sign ? -quotient : quotient;
}


int main() {
    cout << divide(-15,4) << endl;
}