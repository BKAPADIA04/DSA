#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<int>primes(n+1,1);
    primes[0] = 0; primes[1] = 0; primes[n] = 0;

    for(int i = 2;i * i <= n;i++) {
        for(int j = i*i;j <= n;j+=i) {
            primes[j] = 0;
        }
    }       
    for(int i:primes) cout << i << " "; 

    return accumulate(primes.begin(),primes.end(),0); 
}

int main() {
    cout << countPrimes(10) << endl;
    cout << countPrimes(0) << endl;
    cout << countPrimes(3) << endl;
}