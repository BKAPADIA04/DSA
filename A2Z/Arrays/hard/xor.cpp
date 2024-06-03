#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>v = {4, 2, 2, 6, 4};
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int xor_ = 0;
        for(int j = i;j < n;j++) {
            xor_ = xor_ ^ v[j];
            cout << xor_ << " ";
        }
        cout << endl;
    }   

    cout << (6 ^ 7 ^ 8 ^ 9) << endl;
}