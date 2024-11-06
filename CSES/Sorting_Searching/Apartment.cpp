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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n; ll m,k; cin >> m >> k;
    vt<ll>nums(n);
    f(i,0,n) {
        cin >> nums[i];
    }
    vt<ll>ask(m);
    f(i,0,m) {
        cin >> ask[i];
    }
    sort(nums.begin(),nums.end());
    sort(ask.begin(),ask.end());

    ll i = 0, j = 0;
    ll answer = 0ll;
    while(i < n && j < m) {
        if(nums[i] - k <= ask[j] && ask[j] <= nums[i] + k) {
            answer++;
            i++;
            j++;
        }
        else if(nums[i] - k >= ask[j]) {
            j++;
        }
        else if(nums[i] + k <= ask[j]) {
            i++;
        }
    }
    cout << answer << endl;
}