#include <bits/stdc++.h>
using namespace std;
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }

int merge(vector<int>& arr, int low, int mid, int high) {
    int count = 0;
    int left = low; 
    int right = mid + 1;
    vector<int> temp; 
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } 
        else {
            count += (mid - left + 1); // count inversions
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) { temp.push_back(arr[left]);left++; }
    while (right <= high) { temp.push_back(arr[right]); right++;}
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}
int inversionCount(vector<int> &arr, int n)
{
    // Your Code Here
    return mergeSort(arr,0,n - 1);
}


int main() {
    vector<int> a = {2, 4, 1, 3, 5};
    int n = 5;
    int cnt = inversionCount(a,n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}