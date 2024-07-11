#include <bits/stdc++.h>
using namespace std;

vector<int> findPrimeFactors(int n) {
    // Query Based Hota toh 10^5 tak ka solve karte rahenge and then query karte vakt it takes atmost logn iterations
    vector<int>primes(n+1,0);
    for(int i = 2;i <= n;i++) primes[i] = i;

    for(int i = 2;i * i <= n;i++) {
        if(primes[i] == i) {
            for(int j = i*i;j <= n ;j+=i) {
                if(primes[j] == j)
                    primes[j] = i;
            }
        }
    }
    vector<int>ans;
    while(n != 1) {
        ans.push_back(primes[n]);
        n = n/primes[n];
    }

    return ans;
}

int main() {
    vector<int>answer = findPrimeFactors(12246);
    for(int i :answer) cout << i << " ";
    cout << endl;
}