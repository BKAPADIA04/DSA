#include <bits/stdc++.h>
  using namespace std;
  
  vector<int> pri(int n) 
  {
    vector<int> result;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            result.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) 
    {
        result.push_back(n);
    }
    return result;
}

  int main() {

    string s;
    cin >> s;
    
    string t = s;
    reverse(t.begin(), t.end());
    
    if(t == s)
    {
      cout << 1;
      return 0;
    }
    
    int n = s.size();
    
    vector<int> prime = pri(n);
    
    for(int i = 0; i < prime.size(); i++)
    {
      int l = 0;
      int r = n - prime[i];
      int flag = 0;
      while(l <= r)
      {
        if(s.substr(l, prime[i]) == s.substr(r, prime[i]))
        {
          l = l + prime[i];
          r = r - prime[i];
        }
        else
        {
          flag = 1;
          break;
        }
      }
      if(flag == 0)
      {
        cout << prime[i];
        return 0;
      }
    }
    
    cout << -1;

    return 0;

  }
