#include <bits/stdc++.h>
using namespace std;

long long power(long long x,long long n) {
    long long mod = 1e9 + 7; 
    if(n == 0) return 1;
    long long answer = power(x,n/2);
    answer *= answer;
    answer %= mod;
    if(n%2) answer *= x;
    answer %= mod;
    return answer;
}

int countGoodNumbers(long long n) {
    // there are fixed number of odd and even indices
    // odd indices can have values - 2,3,5,7 = 4 values
    // even indices can have values - 0,2,4,6,8 = 5 values
    // Permutation and Combination -> odd^4 * even^5 possibilies

    long long odd = n/2;
    long long even = n/2 + n%2;
    long long mod = 1e9 + 7; 
    return (power(4,odd) * power(5,even)) % mod;
}

int main() {
    cout << countGoodNumbers(806166225460393) << endl;
}