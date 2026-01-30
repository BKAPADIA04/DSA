class Solution {
public:

    vector<vector<bool>>visited;
    int m,n;

    bool isValid(int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if(visited[x][y]) return;

        visited[x][y] = true;

        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }

        int adjMines = 0;
        vector<int>tempX = {-1,0,1};
        vector<int>tempY = {-1,0,1};

        if(board[x][y] == 'E') {
            for(int i = 0;i < 3;i++) {
                for(int j = 0;j < 3;j++) {
                    int newX = x + tempX[i];
                    int newY = y + tempY[j];
                    if(x == newX && y == newY) continue;
                    if(!isValid(newX,newY)) continue;
                    if(board[newX][newY] == 'M') adjMines++;
                }
            }

            if(adjMines == 0) {
                board[x][y] = 'B';
                for(int i = 0;i < 3;i++) {
                    for(int j = 0;j < 3;j++) {
                        int newX = x + tempX[i];
                        int newY = y + tempY[j];
                        if(x == newX && y == newY) continue;
                        if(!isValid(newX,newY)) continue;
                        dfs(board, newX, newY);
                    }
                }
            }
            else {
                board[x][y] = adjMines + '0';
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();

        visited = vector<vector<bool>>(m,vector<bool>(n,false));

        dfs(board, click[0], click[1]);

        return board;
    }
};
