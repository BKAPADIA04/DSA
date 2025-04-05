class Solution {
public:

    void print(vector<vector<int>>answer) {
        for(auto it:answer) {
            for(auto it1:it) {
                cout << it1 << " ";
            }
            cout << endl;
        }
    }

    bool isValid(int n,int m,int x,int y) {
        if(x < 0 || y < 0 || x >= n || y >= m) return false;
        return true;
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int up = 0; int down = rows - 1; int left = 0; int right = cols - 1;
        vector<vector<int>>answer;
        int x = rStart; int y = cStart;
        int add = 1;
        answer.push_back({x,y});
        while(answer.size() < (rows * cols)) {
            y = y + 1;
            int newY = y + add - 1;
            for(int i = y; i <= newY;i++) {
                if(isValid(rows,cols,x,i) && answer.size() < (rows * cols)) answer.push_back({x, i});
            }
            y = newY;

            x = x + 1;
            int newX = x + add - 1;
            for(int i = x; i <= newX;i++) {
                if(isValid(rows,cols,i,y) && answer.size() < (rows * cols)) answer.push_back({i, y});
            }
            x = newX;

            add++;

            y = y - 1;
            newY = y - add + 1;
            for(int i = y; i >= newY;i--) {
                if(isValid(rows,cols,x,i) && answer.size() < (rows * cols)) answer.push_back({x, i});
            }
            y = newY;

            x = x - 1;
            newX = x - add + 1;
            for(int i = x;i >= newX;i--) {
                if(isValid(rows,cols,i, y) && answer.size() < (rows * cols)) answer.push_back({i, y});
            }
            x = newX;

            add++;
        }
        return answer;
    }
};
