#include <bits/stdc++.h>
using namespace std;

string oddEven(int N){
    if((N & 1) == 0) return "even";
    else return "odd";
}

int main() {
    cout << oddEven(45) << endl;
}