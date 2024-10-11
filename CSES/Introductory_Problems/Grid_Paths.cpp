#include <bits/stdc++.h>
using namespace std; 
#define vt vector
#define pb push_back
#define ll long long
#define ld long double
#define ar array
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }
#define print_h(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << " "; }
#define f(i,s,n) for(int i=s;i<n;i++)
#define r(i,s,n) for(int i=n-1;i>=0;i--)
#define cf(i,s,n) for(int i=s;i<=n;i++)
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }
#define MOD 1000000007
#define endl "\n"
const ll INF = 0x3f3f3f3f3f3f3f3f;

bool boundary(int i,int j) {
    return (i >= 0 && i < 7 && j >= 0 && j < 7);
}

void dfs(int i,int j,string str,int index,vt<vt<int> >&visited,int &answer) {
    if(index == 48) {
        answer += ((index == 48) && (i == 6 && j == 0));
        return;
    }

    //reached vertical boundary 
    if((!boundary(i-1,j) || visited[i-1][j]) && (!boundary(i+1,j) || visited[i+1][j]))
        if(boundary(i,j-1) && !visited[i][j-1] && boundary(i,j+1) && !visited[i][j+1]) 
            return;

    // reached horizontal boundary 
    if((!boundary(i,j-1) || visited[i][j-1]) && (!boundary(i,j+1) || visited[i][j+1]))
        if(boundary(i-1,j) && !visited[i-1][j] && boundary(i+1,j) && !visited[i+1][j]) 
            return;
        
    visited[i][j] = 1;
    if(str[index] == 'U' || str[index] == '?')
        if(boundary(i-1,j) && !visited[i-1][j])
            dfs(i-1,j,str,index + 1,visited,answer);
    
    if(str[index] == 'D' || str[index] == '?')
        if(boundary(i+1,j) && !visited[i+1][j])
            dfs(i+1,j,str,index + 1,visited,answer);

    if(str[index] == 'L' || str[index] == '?')
        if(boundary(i,j-1) && !visited[i][j-1])
            dfs(i,j-1,str,index + 1,visited,answer);

    if(str[index] == 'R' || str[index] == '?')
        if(boundary(i,j+1) && !visited[i][j+1])
            dfs(i,j+1,str,index + 1,visited,answer);
    visited[i][j] = 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    // string c(48, '?');

    vt<vt<int> >visited(7,vt<int>(7,0));
    
    // print_h(dp[6]);
    int answer = 0;
    dfs(0,0,str,0,visited,answer);
    cout << answer << endl;
}