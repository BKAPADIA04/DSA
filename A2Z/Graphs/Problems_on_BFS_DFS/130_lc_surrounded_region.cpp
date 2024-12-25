class Solution {
public:

    bool isValid(int x,int y,int m, int n) {
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    void dfs(vector<vector<char>>& board,vector<vector<int>>& visited,int x,int y,int m,int n) {
        visited[x][y] = 1;
        if(isValid(x+1,y,m,n) && board[x+1][y] == 'O' && visited[x+1][y] == 0) 
            dfs(board,visited,x+1,y,m,n);
        if(isValid(x-1,y,m,n) && board[x-1][y] == 'O' && visited[x-1][y] == 0) 
            dfs(board,visited,x-1,y,m,n);
        if(isValid(x,y+1,m,n) && board[x][y+1] == 'O' && visited[x][y+1] == 0) 
            dfs(board,visited,x,y+1,m,n);
        if(isValid(x,y-1,m,n) && board[x][y-1] == 'O' && visited[x][y-1] == 0) 
            dfs(board,visited,x,y-1,m,n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i = 0;i < m;i++) {
            if(visited[i][0] == 0 && board[i][0] == 'O') dfs(board,visited,i,0,m,n);
            if(visited[i][n-1] == 0 && board[i][n-1] == 'O') dfs(board,visited,i,n-1,m,n);
        }

        for(int i = 0;i < n;i++) {
            if(visited[0][i] == 0 && board[0][i] == 'O') dfs(board,visited,0,i,m,n);
            if(visited[m-1][i] == 0 && board[m-1][i] == 'O') dfs(board,visited,m-1,i,m,n);
        }


        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                // cout << visited[i][j] << " ";
                if(board[i][j] == 'O' && visited[i][j] == 0) board[i][j] = 'X';
            }
            cout << endl;
        }
    }
};