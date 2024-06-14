#include <bits/stdc++.h>
using namespace std;

int check(int n,int arr[],long long mid) {
    int students = 1;
    long long sum = 0ll;
    for(int i = 0;i < n;i++) {
        if(sum + arr[i] <= mid) {
            sum += arr[i];
        }
        else {
            students++;
            sum = arr[i];
        }
    }
    return students;
}


long long findPages(int n, int arr[], int m) {
    // code here

    if (m > n) return -1;
    // sort(arr,arr+n);

    // min = max no of pages -> 1 book to each student
    // max = sum of pages -> n books to 1 student

    long long low = arr[n - 1];
    long long high = accumulate(arr,arr+n,0);
    long long result = -1;
    while(low <= high) {
        long long mid = (low + high) / 2;
        long long answer = check(n,arr,mid);
        if(answer <= m) {
            result = mid;
            high = mid - 1;
            // cout << result << endl;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int arr[] = {12,34,67,90};
    int n = 4;
    int m = 2;
    int ans = findPages(n,arr, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}