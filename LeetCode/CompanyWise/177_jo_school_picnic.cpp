#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll mod = 1e9 + 7;

int main() {
  ll n; cin >> n;
  vector<ll>nums1(n),nums2(n);
  for(ll i = 0;i < n;i++) cin >> nums1[i];
  for(ll i = 0;i < n;i++) cin >> nums2[i];
  
  ll index1 = 0ll; ll index2 = 0ll;
  for(ll i = 1;i < n;i++) {
    if(nums1[i] < nums1[index1]) index1 = i;
  }
  for(ll i = 1;i < n;i++) {
    if(nums2[i] < nums2[index2]) index2 = i;
  }
  
  ll ans = 0ll;
  for(ll i = 0; i < n;i++) {
    if(i != index1 && i != index2) {
      ll temp1 = (nums1[i] * nums2[index2]);
      ll temp2 = (nums2[i] * nums1[index1]);
      
      ans = (ans + min(temp1,temp2) % mod) % mod;
    }
  }
  if(index1 != index2) {
    ans = (ans + (nums1[index1] * nums2[index2]) % mod) % mod;
  }
  
  cout << ans << endl;
  
}
