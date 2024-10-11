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
#define MOD 1000000007
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

ll binpow(ll x, ll y)
{
    ll ans = 1;
 
    while (y > 0)
    {
        if (y % 2 == 1)
            ans *= x;
 
        x = x * x;
        y = y / 2;
 
        x %= MOD;
        ans %= MOD;
    }
 
    return ans;
}

vector<string>answer(int n) {
    if(n == 1) {
        vector<string>base;
        base.pb("0");
        base.pb("1");
        return base;
    }
    vector<string>prevLevel = answer(n-1);

    vector<string>reversedPrevLevel = prevLevel;
    reverse(reversedPrevLevel.begin(),reversedPrevLevel.end());

    int index = 0;
    int prevSize = prevLevel.size();
    while(index < prevSize) {
        string appendedZero = "0" + prevLevel[index];
        prevLevel[index] = "1" + reversedPrevLevel[index];
        prevLevel.pb(appendedZero);
        index++;
    }
    return prevLevel;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    vector<string>grayCode;
    grayCode = answer(n);
    print(grayCode);
};