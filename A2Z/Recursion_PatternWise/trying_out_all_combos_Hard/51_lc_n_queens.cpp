#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,vector <string> board,int n) {
    int temp_row = row;
    int temp_col = col;
    while(temp_row >= 0 && temp_col >= 0) {
        if(board[temp_row][temp_col] == 'Q') return false;

        temp_row--;
        temp_col--;
    }

    temp_row = row;
    temp_col = col;
    while(temp_col>= 0) {
        if(board[temp_row][temp_col] == 'Q') return false;
        temp_col--;
    }

    temp_row = row;
    temp_col = col;
    while(temp_row < n && temp_col >= 0) {
        if(board[temp_row][temp_col] == 'Q') return false;
        temp_row++;
        temp_col--;
    }

    return true;
}

void generate(vector<vector<string>>&ans,int col,vector<string>&board,int n) {
    if(col == n) {
        ans.push_back(board);
        return;
    }

    for(int i = 0;i < n;i++) {
        if(isSafe(i,col,board,n)) {
            board[i][col] = 'Q';
            generate(ans,col+1,board,n);
            board[i][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string>board(n);
    string str(n,'.');
    for(int i = 0;i < n;i++) board[i] = str;
    generate(ans,0,board,n);
    return ans;
}



int main() {
    vector<vector<string>> ans = solveNQueens(2);
    for(int i = 0;i < ans.size();i++) {
        for(int j = 0;j < ans[i].size();j++) {
            cout << ans[i][j] << " , ";
        }
        cout << endl;
    }
}