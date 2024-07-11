#include <bits/stdc++.h>
using namespace std;

void print_divisors(int n) {
    vector<int>larger;
    for(int i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) { 
            cout << i << " ";
            if(i != (n/i)) larger.push_back(n/i);
        }
    }
    for(int i = larger.size() - 1;i >= 0;i--) {
        cout << larger[i] << " ";
    }
}

int main() {
    print_divisors(20);cout << endl;
    print_divisors(21191);
}