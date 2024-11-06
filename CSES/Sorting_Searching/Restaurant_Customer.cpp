
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

    int n; cin >> n;
    vt<int>start;vt<int>end;

    // sweep line algo to handle intervals.The core idea is to conceptually "sweep" a vertical or horizontal line across a plane to process events in a specific order, usually based on their coordinates. 

    f(i,0,n) {
        ll s,e;
        cin >> s >> e;
        start.push_back(s);
        end.push_back(e);
    }

    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    
    int answer = 0; int count = 0;
    int i = 0; int j = 0;
    while(i < n && j < n) {
        if(start[i] < end[j]) {
            count++;
            answer = max(answer,count);
            i++;
        }
        else {
            count--;
            j++;
        }
    }
    cout << answer << endl;
}

// better
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    // Vector to hold events (arrival as +1, leaving as -1)
    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++) {
        int arrival, leaving;
        cin >> arrival >> leaving;
        events.push_back({arrival, 1});   // +1 for arrival
        events.push_back({leaving, -1});  // -1 for leaving
    }

    // Sort events. If two events have the same time, prioritize arrivals first
    sort(events.begin(), events.end());

    int max_customers = 0;
    int current_customers = 0;

    // Traverse through sorted events
    for (auto event : events) {
        current_customers += event.second;  // Add or subtract based on event type
        max_customers = max(max_customers, current_customers); // Track max customers
    }

    cout << max_customers << endl;
    return 0;
}

