#include <bits/stdc++.h>
using namespace std;

int findXOR(int l, int r) {
    // XOR Pattern
    // N % 4 == 1 -> 1
    // N % 4 == 2 -> N+1
    // N % 4 == 3 -> 0
    // N % 4 == 0 -> N

    int answer = 0;
    if(r % 4 == 1) answer = 1;
    else if(r % 4 == 2) answer = r + 1;
    else if(r % 4 == 3) answer = 0;
    else answer = r;

    int check = l - 1;
    if(check % 4 == 1) answer ^= 1;
    else if(check % 4 == 2) answer ^= (check+1);
    else if(check % 4 == 3) answer ^= 0;
    else answer ^= check;

    return answer;
}

int main() {
    cout << findXOR(4,8) << endl;
}