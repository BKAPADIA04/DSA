#include <bits/stdc++.h>
#include <iostream>
using namespace std; 
#define vt vector
#define pb push_back
#define ll long long
#define ld long double
#define ar array
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }

int answer(int n,int k) {
    int count = 0;
    if(k == 0) return 0;
    if(n > k) return 1;
    else {
        k = k - n;
        count++;
        int counter = n - 1; int times = 1;
        while(k > 0) {
            k = k - counter;
            count++;
            if(k <= 0) return count;

            if(times & 1) {
                times = 0;
            }
            else {
                counter--;
                times = 1;
            }
        }
    }
    return count;
}


int main() {
    int t; cin >> t;
    vt<int>ans;
    while(t--) {
        int n,k;
        cin >> n >> k;
        ans.push_back(answer(n,k));
    }
    for(int i:ans) cout << i << endl;
}