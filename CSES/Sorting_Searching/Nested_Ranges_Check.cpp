#include <bits/stdc++.h>
using namespace std; 
#define vt vector
#define pb push_back
#define ll long long
#define ld long double
#define ar array
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }
#define print_h(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << " "; }
#define f(i,s,n) for(ll i=s;i<n;i++)
#define r(i,s,n) for(ll i=n-1;i>=0;i--)
#define cf(i,s,n) for(ll i=s;i<=n;i++)
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }
#define MOD 1000000007
#define endl "\n"
const ll INF = 0x3f3f3f3f3f3f3f3f;

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
bool comparator(vector<ll>a,vector<ll>b) {
    if(a[0] == b[0]) {
        return b[1] < a[1];
    }
    return a[0] < b[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    vector<vector<ll> >v;
    f(i,0,t) {
        ll n; cin >> n; ll m ; cin >> m;
        vt<ll>temp;
        temp.pb(n); temp.pb(m); temp.pb(i);
        v.pb(temp);
    }
    if(t == 1) {
        cout << 1 << endl << 1 << endl;
    }
    else {
        sort(v.begin(),v.end(),comparator);
        // for(auto it:v) {
        //     cout << it[0] << " " << it[1] <<" " << it[2] << endl;
        // }

        vt<ll>contains(t);
        ll min_right = v[t-1][1];
        for(ll i = t - 2;i >= 0;i--) {
            ll right_end = v[i][1];
            if(right_end >= min_right) {
                contains[v[i][2]] = 1;
            }
            min_right = min(min_right,right_end);
        }
        print_h(contains);
        vt<ll>contained(t);
        ll max_right = v[0][1];
        for(ll i = 1;i < t;i++) {
            ll right_end = v[i][1];
            if(right_end <= max_right) {
                contained[v[i][2]] = 1;
            }
            max_right = max(max_right,right_end);
        }
        cout << endl;
        print_h(contained);
    }
}