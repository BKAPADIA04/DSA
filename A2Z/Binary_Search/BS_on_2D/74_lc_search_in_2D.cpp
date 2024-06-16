#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low_row = 0; int high_row = m - 1;
    while(low_row <= high_row) {
        int mid_row = (low_row + high_row) / 2;
        if((matrix[mid_row][0] <= target) && (target <= matrix[mid_row][n - 1])) {
            int low_col = 0; int high_col = n - 1;
            while(low_col <= high_col) {
                int mid_col = (low_col + high_col) / 2;
                if(matrix[mid_row][mid_col] == target) return true;
                else if(matrix[mid_row][mid_col] > target) high_col = mid_col - 1;
                else low_col = mid_col + 1;
            }
            return false;
        }
        else if(matrix[mid_row][0] > target) high_row = mid_row - 1;
        else low_row = mid_row + 1;
    }
    return false;
}

// Optimal
bool searchMatrix_(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << searchMatrix(matrix,59) << endl;
    // cout << searchMatrix(matrix,13) << endl;
}