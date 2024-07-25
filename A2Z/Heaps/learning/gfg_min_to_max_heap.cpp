#include <bits/stdc++.h>
using namespace std;

void TopDownMaxHeapify(vector<int>&arr,int n,int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if(left < n && arr[left] > arr[i]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i) {
        swap(arr[i],arr[largest]);
        TopDownMaxHeapify(arr,n,largest);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int n){
    for(int i = ((n-2)/2);i >= 0;i--) TopDownMaxHeapify(arr,n,i);
}

int main() {
    vector<int>arr = {3, 4, 8, 11, 13};
    convertMinToMaxHeap(arr,arr.size());
    for(int i:arr) {
        cout << i << " ";
    }
    cout << endl;
}