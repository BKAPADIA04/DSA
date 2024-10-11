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

    ll n; cin >> n;
    ll sum = (n * (n + 1)) / 2;

    if((sum % 2) == 1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        set<ll>s1,s2;
        ll mean = sum/2;
        for(ll i = n;i >= 1;i--) {
            if(i <= mean) {
                s1.insert(i);
                mean = mean - i;
            }
            else {
                s2.insert(i);
            }
        }
        cout << s1.size() << endl;
        print_h(s1);cout << endl;
        cout << s2.size() << endl;
        print_h(s2);cout << endl;
    }
}