#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    // we can either start from (0,n-1) or (m-1,0)
    int rows = m - 1;
    int cols = 0;
    while(rows >= 0 && rows < m && cols >= 0 && cols < n) {
        if(matrix[rows][cols] == target) return true;
        else if(matrix[rows][cols] > target) rows--;
        else cols++;
    }
    return false;
}

int main() {
    vector<vector<int> > matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout << searchMatrix(matrix,20) << endl;
    // cout << searchMatrix(matrix,13) << endl;
}