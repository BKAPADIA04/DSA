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

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>answer(n,vector<int>(n,-1));
        int up = 0; int down = n - 1; int left = 0; int right = n - 1;
        int counter = 1; int i = 0;
        while(counter <= (n * n)) {
            while(i <= right) {
                answer[up][i] = counter; counter++;
                i++; 
            }
            up++;
            i = up;
            while(i <= down) {
                answer[i][right] = counter; counter++;
                i++;
            }
            right--;

            i = right;
            while(i >= left) {
                answer[down][i] = counter; counter++;
                i--;
            }
            down--;

            i = down;
            while(i >= up) {
                answer[i][left] = counter; counter++;
                i--;
            }
            left++;
            i = left;
        }
        return answer;
    }
};
