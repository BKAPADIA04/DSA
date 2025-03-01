//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

// Back-end complete function Template for C++

#define ll long long
class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        ll n = bt.size();
        vector<pair<int,int>>v;
        for(ll i = 0;i < n;i++) {
            v.push_back({bt[i],i});
        }
        sort(v.begin(),v.end());
        
        ll sum = 0; ll cumu = 0;
        for(ll i = 0;i < n;i++) {
            cumu += v[i].first;
            sum += (cumu - v[i].first);
        }
        return sum/n;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
