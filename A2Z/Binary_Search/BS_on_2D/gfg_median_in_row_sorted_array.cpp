#include <bits/stdc++.h>
using namespace std;

int countSmallerEqual(vector<vector<int>> &matrix, int m, int n, int mid) {
    int answer = 0;
    for(int i = 0;i < m;i++) {
        answer += (upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin());
    }
    return answer;
}

int median(vector<vector<int>> &matrix, int m, int n){
    // code here    
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }
    int result = -1;
    int req = (m * n) / 2;
    while(low <= high) {
        int mid = (low + high) / 2;
        if((countSmallerEqual(matrix,m,n,mid)) <= req) {
            low = mid + 1;
        }
        else {
            result = mid;
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << ans << endl;
}