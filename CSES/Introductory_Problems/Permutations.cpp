#include <bits/stdc++.h>
using namespace std; 
#define vt vector
#define pb push_back
#define ll long long
#define ld long double
#define ar array
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }
#define print_h(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << " "; }
#define f(i,s,n) for(int i=s;i<n;i++)
#define r(i,s,n) for(int i=n-1;i>=0;i--)
#define cf(i,s,n) for(int i=s;i<=n;i++)
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }
const int n1=1e9+7;
#define endl "\n"

bool isPerfectSquare(long long x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {

        long long sr = sqrt(x);
        
        // if product of square root 
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    // if(n == 2 || n == 3) {
    //     cout << "NO SOLUTION" << endl;
    // }
    // else if(n == 4){
    //     cout << 2 << " " << 4  << " " << 1 << " " << 3 << endl;
    // }
    // else {
    //     vt<int>answer(n,0);
    //     int counter = 1;
    //     f(i,0,n) {
    //         if(i % 2 == 0) {
    //             answer[i] = counter++;
    //         }
    //     }
    //     f(i,0,n) {
    //         if(i % 2 == 1) {
    //             answer[i] = counter++;
    //         }
    //     }
    // print_h(answer);
    // }

    // Better Soln
    // Difference between 2 evens and 2 odds = 2 i.e. greater than 1
    vt<ll>answer;
    for(int i = 2;i <= n;i += 2) {
        answer.pb(i);
    }
    for(int i = 1;i <= n;i += 2) {
        answer.pb(i);
    }
    if(n <= 3 && n != 1) {
        cout << "NO SOLUTION" << endl;
    }
    else if(n == 1) cout << 1 << endl;
    else {
        print_h(answer);
    }
}