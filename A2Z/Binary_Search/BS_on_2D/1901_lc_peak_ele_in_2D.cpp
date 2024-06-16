#include <bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    if(n == 1 && m == 1) return {0,0};
    int low = 0; int high = m - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        vector<int>row = mat[mid];
        int maxi = INT_MIN;int index = -1;
        for(int i = 0;i < n;i++) {
            if(row[i] > maxi) {
                maxi = row[i];
                index = i;
            }
        }
        if(m == 1) return {0,index};
        if(mid == 0) {
            if(mat[mid][index] > mat[mid + 1][index]) return {mid,index};
            else low = mid + 1;
        }
        else if(mid == (m - 1)) {
            if(mat[mid][index] > mat[mid - 1][index]) return {mid,index};
            else high = mid - 1;
        }
        else {
            if(mat[mid][index] > mat[mid - 1][index] && mat[mid][index] > mat[mid + 1][index]) {
                return {mid,index};
            }
            else if(mat[mid][index] < mat[mid - 1][index]) high = mid - 1;
            else low = mid + 1;
        }
    }
    return {-1,-1};
}

// Better Trick to Handle Boundary Cases

int findmaxindex(std::vector<std::vector<int>>& mat, int n, int m, int col){
    int maxvalue = -1;
    int index = -1;
    for(int i = 0; i<n; i++){
        if(mat[i][col]>maxvalue){
            maxvalue = mat[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid_(std::vector<std::vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m-1;

    while(low<=high){
        int mid = (high+low)/2;
        int maxrowindex = findmaxindex(mat, n, m, mid);

        int left = mid - 1>=0 ? mat[maxrowindex][mid-1] : -1;
        int right = mid + 1 <m ? mat[maxrowindex][mid+1] : -1;

        if(mat[maxrowindex][mid] > left && mat[maxrowindex][mid] > right){
            return {mid,maxrowindex};
        }
        else if(mat[maxrowindex][mid] < left){
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    } 
    return {-1,-1};
}

int main() {
    vector<vector<int> > matrix = {{1,4},{3,2}};
    vector<int>ans = findPeakGrid(matrix);
    cout << ans[0] << " " << ans[1] << endl;
    vector<vector<int> > matrix1 = {{10,20,15},{21,30,14},{7,16,32}};
    vector<int>ans1 = findPeakGrid(matrix1);
    cout << ans1[0] << " " << ans1[1] << endl;
    vector<vector<int> > matrix2 = {{1,4}};
    vector<int>ans2 = findPeakGrid(matrix2);
    cout << ans2[0] << " " << ans2[1] << endl;

    vector<int>ans4 = findPeakGrid_(matrix);
    cout << ans4[0] << " " << ans4[1] << endl;
}