#define ll long long
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<ll> >&dp) {
  for(auto it: dp) {
    for(auto el: it) {
      cout << el << " ";
    }
    cout << endl;;
  }
  cout << endl;
}

ll check(vector<ll>&weights,vector<ll>&values,vector<vector<ll> >&dp,ll i,ll wt) {
    // if(wt < 0) return LLONG_MIN;
    if(i == 0) {
        if(weights[0] <= wt) return values[0];
        return 0;
    }
    
    if(dp[i][wt] != -1) return dp[i][wt];
    
    ll notTaken = check(weights,values,dp,i-1,wt);
    ll taken = LLONG_MIN;
    if(weights[i] <= wt) {
        ll temp2 = check(weights,values,dp,i-1,wt - weights[i]);
        taken = values[i] + temp2;
    }
    // ll temp2 = check(weights,values,dp,i-1,wt - weights[i]);
    // if(temp2 != LLONG_MIN) {
    //     taken = values[i] + temp2;
    // }
    
    return dp[i][wt] = max(taken,notTaken);
}

int main() {
  ll n; cin >> n; ll w; cin >> w;
  vector<ll>weights(n,0),values(n,0);
  for(ll i = 0;i < n;i++) {
    ll ele1,ele2; cin >> ele1 >> ele2;
    weights[i] = ele1; values[i] = ele2;
  }
//   vector<vector<ll> >dp(n,vector<ll>(w+1,-1));
//   cout << check(weights,values,dp,n-1,w) << endl;
//   print(dp);


    // vector<vector<ll> >dp(n,vector<ll>(w+1,LLONG_MIN));

    vector<ll>prev(w+1,0);
    for(ll i = 0;i <= w;i++) {
        if(weights[0] <= i) prev[i] = values[0];
        else prev[i] = 0;
    }
    
    for(ll i = 1;i < n;i++) {
        vector<ll>curr(w+1,0);
        for(ll wt = 0;wt <= w;wt++) {
        ll notTaken = prev[wt];
        ll taken = LLONG_MIN;
        if(weights[i] <= wt) {
            ll temp2 = prev[wt-weights[i]];
            taken = values[i] + temp2;
        }
        
        curr[wt] = max(notTaken,taken);
        }
        prev = curr;
    }
    cout << prev[w] << endl;
}

// Time Complexity: O(N*W).
// Space Complexity: O(N*W).

