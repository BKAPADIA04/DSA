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

bool comparator(pair<ll,ll>A,pair<ll,ll>B) {
    return A.second < B.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    vt<pair<ll,ll> >nums;
    f(i,0,n) {
        ll start,end;
        cin >> start >> end;
        nums.pb(make_pair(start,end));
    }
    sort(nums.begin(),nums.end(),comparator);

    // for(auto it = nums.begin();it!=nums.end();it++) {
    //     cout << it->first << " " << it->second << endl;
    // }

    set<pair<ll,ll> >answer;
    answer.insert(make_pair(nums[0].first,nums[0].second));
    ll finish = nums[0].second;
    for(ll i = 1;i < n;i++) {
        if(nums[i].first >= finish) {
            answer.insert(make_pair(nums[i].first,nums[i].second));
            finish = nums[i].second;
        }
    }
    // for(auto it = answer.begin();it!=answer.end();it++) {
    //     cout << it->first << " " << it->second << endl;
    // }
    cout << answer.size() << endl;
}