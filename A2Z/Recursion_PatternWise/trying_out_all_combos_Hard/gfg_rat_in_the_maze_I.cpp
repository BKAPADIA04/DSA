#include <bits/stdc++.h>
using namespace std;

void generate(vector<vector<int>> &m,int n,vector<string>&ans,string str,int row,int col,vector<vector<int>> &vis) {
    if(row == n - 1 && col == n - 1) {
        ans.push_back(str);
        return;
    }

    if(row-1 >= 0 && row-1 < n && m[row-1][col] == 1 && !vis[row-1][col]) {
        vis[row][col] = 1;
        generate(m,n,ans,str + "U",row-1,col,vis);
        vis[row][col] = 0;
    }
    if(row+1 >= 0 && row+1 < n && m[row+1][col] == 1 && !vis[row+1][col]) {
        vis[row][col] = 1;
        generate(m,n,ans,str + "D",row+1,col,vis);
        vis[row][col] = 0;
    }
    if(col-1 >= 0 && col-1 < n && m[row][col-1] == 1 && !vis[row][col-1]) {
        vis[row][col] = 1;
        generate(m,n,ans,str + "L",row,col-1,vis);
        vis[row][col] = 0;
    }
    if(col+1 >= 0 && col+1 < n && m[row][col+1] == 1 && !vis[row][col+1]) {
        vis[row][col] = 1; 
        generate(m,n,ans,str + "R",row,col+1,vis);
        vis[row][col] = 0;
    }
}


vector<string> findPath(vector<vector<int>> &m, int n) {
    if(m[0][0] == 0 || m[n-1][n-1] == 0) return {};
    vector<string>ans;
    vector < vector < int >> vis(n, vector < int > (n, 0));
    generate(m,n,ans,"",0,0,vis);
    return ans;
}

int main() {
    int n = 4;
    vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    // vector < vector < int >> m = {{1, 0},{1, 0}};
    vector<string>ans = findPath(m,n);

    if (ans.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}       