#include <bits/stdc++.h>
using namespace std;

int check(vector<vector<int> >&dp,string &str1,string &str2,int i,int j) {
  if(i < 0 || j < 0) return INT_MIN;
  
  if(dp[i][j] != -1) return dp[i][j];
  int count = 0;
  if(str1[i] == str2[j]) {
    int temp = check(dp,str1,str2,i-1,j-1);
    count += 1;
    if(temp != INT_MIN)
      count += temp;
  }
  else {
    int temp1 = check(dp,str1,str2,i,j-1);
    int temp2 = check(dp,str1,str2,i-1,j);
    count = max(count,max(temp1,temp2));
  }
  
  return dp[i][j] = count;
}

int main() {
  string str1,str2;
  cin >> str1 >> str2;
  int m = str1.size(); int n = str2.size();
  
  vector<vector<int> >dp(m,vector<int>(n,-1));
//   check(dp,str1,str2,m-1,n-1);


    vector<vector<int> >dp1(m+1,vector<int>(n+1,0));
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            if(str1[i-1] == str2[j-1]) {
            dp1[i][j] = 1 + dp1[i-1][j-1];
            }
            else {
            dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1]);
            }
        }
    }
    
  int i = m; int j = n;
  string ans = "";
  while(i > 0 && j > 0) {
    if(str1[i-1] == str2[j-1]) {
      ans = str1[i-1] + ans;
      i = i - 1; 
      j = j - 1;
    }
    else if(dp1[i-1][j] > dp1[i][j-1]) {
      i = i - 1;
    }
    else {
      j = j - 1;
    }
  }
    cout << ans << endl;
  
}