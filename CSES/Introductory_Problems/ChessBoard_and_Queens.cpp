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

bool check(vt<vt<int> >&placed,vt<vt<int> >&input) {
    for(int i = 0;i < 8;i++) {
        for(int j = 0;j < 8;j++) {
            if(placed[i][j] && !input[i][j]) return false;
        }
    }
    return true;
}

bool place(int x, int y,vt<vt<int> >&placed){
    bool yes = true;
    for(int i = 0; i < 8; i++)
        if(placed[x][i] || placed[i][y])
            yes = false;
    for(int i = 0; x-i >= 0 && y-i >= 0; i++)
        if(placed[x-i][y-i])
            yes = false;
    for(int i = 0; x-i >= 0 && y+i < 8; i++)
        if(placed[x-i][y+i])
            yes = false;
    return yes;
}


void dfs(int i,int &answer,vt<vt<int> >&placed,vt<vt<int> >&input) {
    if(i == 8) {
        if(check(placed,input))
            answer++;
        return;
    }

    for(int j = 0; j < 8;j++) {
        if(place(i, j,placed)){
            placed[i][j] = 1;
            dfs(i+1,answer,placed,input);
            placed[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vt<vt<int> >input(8,vt<int>(8,-1));
    for(int i = 0;i < 8;i++) {
        for(int j = 0;j < 8;j++) {
            char ch; cin >> ch;
            input[i][j] = (ch == '.');
        }
    }
    vt<vt<int> >placed(8,vt<int>(8,0));
    int answer = 0;
    dfs(0,answer,placed,input);
    cout << answer << endl;
}