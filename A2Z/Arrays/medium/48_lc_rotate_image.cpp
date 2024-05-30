#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(),matrix.end());
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(i < j)
                swap(matrix[i][j],matrix[j][i]);
        }
    }
}
int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << endl;
    }
}