#include <bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (n > m) return kthElement(arr2, arr1,m,n,k);
    int N = n + m;
    int left = k;
    int low = max(0,k-m);
    int high = min(k,n);
    while(low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN; int l2 = INT_MIN; int r1 = INT_MAX; int r2 = INT_MAX; 
        if (mid1 < n) r1 = arr1[mid1];
        if (mid2 < m) r2 = arr2[mid2];

        if (mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = arr2[mid2 - 1];

        if(l1 <= r2 && l2 <= r1) {
            return max(l1,l2);
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1,4,8,10};
    cout << kthElement(arr1,arr2,5,4,5) << endl;

    int arr3[] = {100, 112, 256, 349, 770};
    int arr4[] = {72, 86, 113, 119, 265, 445, 892};
    cout << kthElement(arr3,arr4,5,7,7) << endl;
}