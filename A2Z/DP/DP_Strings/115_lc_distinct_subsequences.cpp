#include <bits/stdc++.h>
using namespace std;

void count(vector<vector<int> >&dp,int i,int j,string str1,string str2,int &answer,string &current) {
    if(i == 0 || j == 0) {
        answer = answer + 1;
        return;
    }
    // cout << i << " " << j << " " << current << endl;
    if(str1[i-1] == str2[j-1]) {
        current += str1[i - 1];
        cout << i << " " << j << " " << current << endl;
        count(dp,i-1,j-1,str1,str2,answer,current);
        current.pop_back();
    }
    else {  
        if(dp[i-1][j] >= dp[i][j-1]) {
            count(dp,i-1,j,str1,str2,answer,current);
        }
        if(dp[i][j-1] >= dp[i-1][j]) {
            count(dp,i,j-1,str1,str2,answer,current);
        }
    }
}

int numDistinct(string str1, string str2) {
    int n = str1.size(); int m = str2.size();
    vector<vector<int> >dp(n+1,vector<int>(m+1,0));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    if(dp[n][m] < str2.size()) return 0;
    int answer = 0;string curr = "";
    count(dp,n,m,str1,str2,answer,curr);
    return answer; 
}

int main() {
    cout << numDistinct("rabbbit","rabbit") << endl;
    cout << numDistinct("babgbag","bag") << endl;
}