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

    ll n; cin >> n;
    vt<pair<ll,ll> >nums;
    f(i,0,n) {
        ll ele; cin >> ele;
        nums.pb(make_pair(ele,i));
    }
    sort(nums.begin(),nums.end());

    ll answer = 1;
    for(ll i = n - 1;i > 0;i--) {
        if(nums[i].second < nums[i-1].second ) answer++;
    }
    cout << answer << endl;
}


// better
#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;

int N, x, cnt, pos[maxN];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &x);
        pos[x] = i;
    }

    cnt = 1;
    for(int i = 2; i <= N; i++)
        if(pos[i-1] > pos[i])
            cnt++;
    printf("%d\n", cnt);
}