#include <bits/stdc++.h>
using namespace std;

bool checkPattern(vector<vector<char>>& board,string word,int i,int rows,int cols,int n,int m) {
    if(i == word.size()) {
        return true;
    }

    if(rows >= n || cols >= m || rows < 0 || cols < 0 || board[rows][cols] != word[i] || board[rows][cols] == '!') return false;

    char c = board[rows][cols];
    board[rows][cols] = '!';

    bool top = checkPattern(board,word,i+1,rows-1,cols,n,m);
    bool bottom = checkPattern(board,word,i+1,rows+1,cols,n,m); 
    bool right = checkPattern(board,word,i+1,rows,cols+1,n,m);
    bool left = checkPattern(board,word,i+1,rows,cols-1,n,m);

    board[rows][cols] = c;

    return top || bottom || right || left;
}


bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();

    int index = 0;

        // First search the first character
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[index]) {
                    if (checkPattern(board, word, index, i, j, n, m))
                        return true;
                }
            }
        }

        return false;

    // return checkPattern(board,word,0,0,0,n,m);
}

int main() {
    vector<vector<char>> board {{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};

    string word = "BCCED";

    bool res = exist(board, word);
    if(res==1)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}