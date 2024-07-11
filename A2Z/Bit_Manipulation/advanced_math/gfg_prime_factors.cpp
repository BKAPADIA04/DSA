#include <bits/stdc++.h>
using namespace std;

vector<int>AllPrimeFactors(int n) {
    vector<int>primes;
    for(int i = 2;i <= sqrt(n);i++) {
        if(i != 2 && ((i & 1) == 0)) continue;
        if(n % i == 0) primes.push_back(i);
        while(n % i == 0) n = n/i;
    }

    if(n != 1) primes.push_back(n);
    return primes;
}

int main() {
    // vector<int>answer = AllPrimeFactors(35);
    // vector<int>answer = AllPrimeFactors(37);
    vector<int>answer = AllPrimeFactors(780);
    for(int i:answer) cout << i << " ";
    cout << endl;
}