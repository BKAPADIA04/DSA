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

ll check(vt<pair<ll,ll> > &v) {
    ll answer = 1; ll n = v.size();
    for(ll i = n-1; i > 0;i--) {
        if(v[i-1].second > v[i].second) answer++;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n; ll m; cin >> m;
    vt<ll>nums(n);
    f(i,0,n) {
        cin >> nums[i];
    }

    vt<pair<ll,ll> >v;
    f(i,0,n) {
        v.pb(make_pair(nums[i],i+1));
    }

    sort(v.begin(),v.end());
// for(auto it:v) cout << it.first << " " << it.second << endl; 
// cout << "ji" << endl;
    for(ll i = 0;i < m;i++) {
        ll a,b; cin >> a >> b;
        ll temp_index = v[nums[a-1]-1].second;
        v[nums[a-1]-1].second = v[nums[b-1]-1].second ;
        v[nums[b-1]-1].second = temp_index;

        // for(auto it:v) cout << it.first << " " << it.second << endl;
        cout << check(v) << endl;
    }

}