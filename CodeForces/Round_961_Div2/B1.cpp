#include <bits/stdc++.h>
#include <iostream>
using namespace std; 
#define vt vector
#define pb push_back
#define ll long long
#define ld long double
#define ar array
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }

ll int answer(int n,ll int m,vector<int>nums) {
    sort(nums.begin(),nums.end(),greater<int>());
    int left = 0; int right = 0; ll int ans = 0ll; ll int maxi = 0ll;
    if(n == 0 || m == 0) return 0;
    while(right < n) {
        if((nums[left] - nums[right]) <= 1) {
            // if(ans + (nums[right] * 1ll) <= m)
            ans += (nums[right] * 1ll);
            if(ans <= m)
                maxi = max(maxi,ans);
            else {
                ans -= (nums[left] * 1ll);
                left++;
            }
        }
        else {
            ans -= (nums[left] * 1ll);
            left++;
            ans += (nums[right] * 1ll);
        }
        right++;
    }
    return maxi;
}


int main() {
    int t; cin >> t;
    vt<ll int> ans;
    while(t--) {
        int n; cin >> n;
        ll int m; cin >> m;
        vector<int>nums(n,0);
        for(int i = 0;i < n;i++) {
            cin >> nums[i];
        }
        ans.pb(answer(n,m,nums));
    }
    print(ans);
}