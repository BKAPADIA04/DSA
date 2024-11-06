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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // set<pair<ll,ll> >s;
    ll n; cin >> n; ll m; cin >> m;
    ll answer = 0;
    // f(i,0,m) {
    //     ll ele; cin >> ele;
    //     if(s.empty()) {
    //         s.insert(make_pair(0,ele));
    //         answer = max(answer,ele);
    //         s.insert(make_pair(ele,n));
    //         answer = max(answer,n-ele);
    //         cout << answer << " ";
    //     }
    //     else {
    //         for(auto it = s.begin();it!=s.end();it++) {
    //             if(ele >= it->first && ele <= it->second) {
    //                 s.insert(make_pair(it->first,ele));
    //                 answer = max(answer,ele-it->first);
    //                 s.insert(make_pair(ele,it->second));
    //                 answer = max(answer,it->second-ele);
    //                 s.erase(it);
    //                 break;
    //             }
    //         }
    //         ll temp = 0;
    //         for(auto it = s.begin();it!=s.end();it++) {
    //             temp = max(temp,it->second-it->first);
    //         }
    //         cout << temp << " ";
    //     }
    // }
    
    set<pair<ll,ll> >s;
    multiset<ll>length;
    s.insert(make_pair(0,n));
    length.insert(n);
    
    f(i,0,m) {
        ll ele; cin >> ele;

        auto it = s.upper_bound(make_pair(ele,0)); 
        --it;
        
        ll start = it->first;
        ll end = it->second;

        s.erase(it);
        length.erase(length.find(end-start));
        s.insert(make_pair(start,ele));
        s.insert(make_pair(ele,end));
        length.insert(ele - start);
        length.insert(end - ele);

        cout << *length.rbegin() << " ";
    }
}