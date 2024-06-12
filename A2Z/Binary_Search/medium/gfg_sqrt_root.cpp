#include <bits/stdc++.h>
using namespace std;
long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    long long int low = 0;
    long long int high = x;
    long long int ans = -1;
    while(low <= high) {
        long long int mid = (low + high) / 2;
        if(mid * mid > x) high = mid - 1;
        else { ans = mid;low = mid + 1;}
    }
    return ans;
}

int main() {
    long long int x = 5;
    cout << floorSqrt(x) << endl;
}