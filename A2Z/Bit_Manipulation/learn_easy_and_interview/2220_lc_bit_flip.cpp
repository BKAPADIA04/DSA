#include <bits/stdc++.h>
using namespace std;




int minBitFlips(int start, int goal) {
    int xorr = start ^ goal;
    int answer = 0;
    while(xorr) {
        answer += (xorr & 1);
        xorr = xorr >> 1;
    }
    return answer;
}

int main() {
    cout << minBitFlips(3,4) << endl;
    cout << minBitFlips(0,4) << endl;
}