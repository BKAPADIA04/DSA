#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<ll> A, B;
ll m;
vector<vector<int>> dp; // 0: unvisited, 1: valid path, 2: invalid path
map<pair<int, int>, string> path; // for storing minimum string at each valid state

bool check(int index, int sum, string &ans, string temp) {
  if (sum > m) return false;
  if (index == A.size()) {
    if (sum == m) {
      if (temp < ans) ans = temp;
      return true;
    }
    return false;
  }

  if (dp[index][sum] == 1) {
    if (temp >= path[{index, sum}]) return false;
  } else if (dp[index][sum] == 2) {
    return false;
  }

  bool opt = false;
  
  temp.push_back('0');
  bool takeA = check(index + 1, sum + A[index], ans, temp);
  temp.pop_back();
  
  temp.push_back('1');
  bool takeB = check(index + 1, sum + B[index], ans, temp);
  temp.pop_back();
  
  opt = takeA || takeB;
  if (opt) {
    dp[index][sum] = 1;
    path[{index, sum}] = temp;
  } else {
    dp[index][sum] = 2;
  }
  return opt;
}

int main() {
  ll n;
  cin >> n >> m;
  A = B = vector<ll>(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  for (ll i = 0; i < n; i++) cin >> B[i];
  
  string ans = string(n, '2');
  string temp;

  dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
  
  if (check(0, 0, ans, temp)) {
    cout << "YES" << endl;
    cout << ans << endl;
  } else {
    cout << "NO" << endl;
  }
}
