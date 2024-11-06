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
#define p pair<ll,ll>

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

    ll n; cin >> n;
    vt<vt<ll> >v;
    f(i,0,n) {
        ll start,end; cin >> start >> end;
        vt<ll>temp; temp.pb(start); temp.pb(end); temp.pb(i);
        v.pb(temp);
    }
    sort(v.begin(),v.end());
    vt<ll>answer(n);
    priority_queue<p,vt<p>,greater<p> >pq;
    f(i,0,n) {
        ll start = v[i][0];
        ll end = v[i][1];
        ll index = v[i][2];
        if(pq.empty()) {
            pq.push(make_pair(end,1));
            answer[index] = 1;
        }
        else {
            p top = pq.top();
            ll end_ = top.first;
            ll class_ = top.second;
            if(start > end_) {
                pq.pop();
                pq.push(make_pair(end,class_));
                answer[index] = class_;
            }
            else {
                answer[index] = pq.size() + 1;
                pq.push(make_pair(end,pq.size()+1));
            }
        }
    }
    cout << pq.size() << endl;
    print_h(answer);
}