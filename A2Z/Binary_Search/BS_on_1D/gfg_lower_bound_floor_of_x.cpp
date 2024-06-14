#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<long long> v, long long n, long long x){
        
    // Your code here
    long long low = 0;
    long long high = n - 1;
    int index = -1;
    while(low <= high) {
        long long mid = (low + high) / 2;
        if(v[mid] <= x) { index = mid; low = mid + 1; }
        else  high = mid - 1;
    }
    return index;
}

int main() {
    vector<long long>v = {1,2,8,10,11,12,19};
    cout << findFloor(v,7,0) << endl;
    cout << findFloor(v,7,5) << endl;
    cout << findFloor(v,7,11) << endl;
    vector<long long> numbers = {
        66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130
    };
    cout << findFloor(numbers,65,106) << endl;
}