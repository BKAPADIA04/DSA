#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int main() {
  int n; cin >> n;
  int m; cin >> m;
  
  vector<int>nums1(n-1);vector<int>nums2(m-1);
  for(int i = 0;i < nums1.size();i++) cin >> nums1[i];
  for(int i = 0;i < nums2.size();i++) cin >> nums2[i];
  
  sort(nums1.begin(),nums1.end());
  sort(nums2.begin(),nums2.end());
  
  int rowComponents = n;
  int colComponents = m;
  
  int answer = 0;
  int i = 0; int j = 0;
  
  while(i < n - 1 && j < m - 1) {
    if(nums1[i] < nums2[j]) {
      answer = (answer + ((long long)colComponents * nums1[i]) % mod) % mod;
      i++;
      rowComponents--;
    } 
    else {
      answer = (answer + ((long long)rowComponents * nums2[j]) % mod) % mod;
      j++;
      colComponents--;
    }
  }
  
  while(i < n - 1) {
    answer = (answer + ((long long)colComponents * nums1[i]) % mod) % mod;
    i++;
    rowComponents--;
  }
  
  while(j < m - 1) {
    answer = (answer + ((long long)rowComponents * nums2[j]) % mod) % mod;
    j++;
    colComponents--;
  }
  cout << answer << endl;
}
