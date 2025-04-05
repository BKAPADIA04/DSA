class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>answer;
        int n = matrix.size();
        int m = matrix[0].size();

        int right = m - 1;
        int down = n - 1;
        int up = 0; 
        int left = 0;

        int counter = 1; int i = 0;
        while(counter <= (n * m)) {
            i = left;
            while(i <= right && counter <= (n * m)) {
                answer.push_back(matrix[up][i]); counter++;
                i++; 
            }
            up++;
            
            i = up;
            while(i <= down && counter <= (n * m)) {
                answer.push_back(matrix[i][right]); counter++;
                i++;
            }
            right--;
            
            i = right;
            while(i >= left && counter <= (n * m)) {
                answer.push_back(matrix[down][i]); counter++;
                i--;
            }
            down--;

            i = down;
            while(i >= up && counter <= (n * m)) {
                answer.push_back(matrix[i][left]); counter++;
                i--;
            }
            left++;
        }
        return answer;
    }
};
