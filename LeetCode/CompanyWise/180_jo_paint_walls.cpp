// #include <bits/stdc++.h>
// using namespace std;

// int check(string &s, int k, char ch) {
//   int n = s.size();
//   int left = 0; int right = 0;
//   int maxi = 0;
  
//   while(right < n) {
//     // cout << left << " " << right << " " << k << endl;
//     if(s[right] != ch) { k--; }
//     if(k < 0) {
//       // cout << left << " " << right << " " << k << endl;
//       if(s[left] != ch) k++;
//       left++;
//     }
    
//     // cout << left << " " << right << endl;
//     maxi = max(maxi, right - left + 1);
//     right++;
//   }
//   return maxi;
// }

// int main() {
//   string s;
//     cin >> s;
//     int k;
//     cin >> k;
  
//   int ans = 0;
//   for(char ch = 'a';ch <= 'z';ch++) {
//     ans = max(ans,check(s,1,ch));
//   }
//   cout << ans << endl;
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    vector<int> v(26, 0);
    int l = 0, r = 0;
    int cnt = 0;
    int maxi = 0;
    int ans = 0;

    while (r < n) {
        v[s[r] - 'a']++; // update frequency of current character

        // calculate max frequency in current window
        maxi = *max_element(v.begin(), v.end());

        cnt = (r - l + 1) - maxi; // number of changes needed

        // if more changes than allowed, shrink window
        while (cnt > k) {
            v[s[l] - 'a']--;
            l++;
            maxi = *max_element(v.begin(), v.end());
            cnt = (r - l + 1) - maxi;
        }

        ans = max(ans, r - l + 1);
        r++;
    }

    cout << ans << endl;
}
