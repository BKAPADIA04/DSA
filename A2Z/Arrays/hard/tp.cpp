#include <bits/stdc++.h>
using namespace std;

int main() {
        int xr = 0;
        vector<int> a = {1,2,3,4,6,7,6};
        int n = a.size();
        //Step 1: Find XOR of all elements:
        for (int i = 0; i < n; i++) {
            xr = xr ^ a[i];
            xr = xr ^ (i + 1);
        }
        int diff_bit = xr & ~(xr - 1);
        // we can find diff bit (the rightmost set bit by this as well):
        int bitNo = 0;
        while(1) {
            if((xr & (1 << bitNo)) != 0) break;
            bitNo++; 
        } 
        int ones = 0;int zeros = 0;
        for(int i = 0;i < n;i++) {
            // 1 club
            if((a[i] & (1 << bitNo)) != 0) ones ^= a[i];
            // 0 club
            else zeros ^= a[i];
        }
        for(int i = 1;i <= n;i++) {
            // 1 club
            if((i & (1 << bitNo)) != 0) ones ^= i;
            // 0 club
            else zeros ^= i;
        }
        // Manual check
        int count = 0;
        for(int i = 0;i < n;i++) {
            if(a[i] == ones) count++;
        }
        if(count == 0) {
            cout << "Repeating = "<< zeros << endl;
            cout << "Missing = "<< ones << endl;
        }
        else {
            cout << "Repeating = "<< ones << endl;
            cout << "Missing = "<< zeros << endl;
        }
}