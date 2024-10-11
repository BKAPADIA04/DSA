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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str; cin >> str;

    vt<int>v(26,0);
    f(i,0,str.size()) {
        v[str[i] - 'A']++;
    }

    char ch = '\0';
    int comp = 0;
    f(i,0,26) {
        if(v[i] & 1) {
            comp++;
            ch = i + 'A';
        }
    }
    if((str.size() % 2 == 0 && comp) || (str.size() % 2 == 1 && comp >= 2)) cout << "NO SOLUTION" << endl;
    else {
        string temp = str;
        if(str.size() % 2 == 1) {
            temp[str.size()/2] = ch;
            v[ch-'A']--;
        }
        int l = 0; int r = str.size() - 1;
        f(i,0,26) {
            if(v[i] % 2 == 1) { temp = "NO SOLUTION"; break;}
            else {
                cf(j,1,v[i]/2) {
                    temp[l++] = i + 'A';
                    temp[r--] = i + 'A';
                }
            }
        }
    cout << temp << endl;
    }
}