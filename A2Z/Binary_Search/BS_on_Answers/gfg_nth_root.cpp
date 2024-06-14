#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
    // Code here.
    int low = 0;
    int high = m;
    while(low <= high) {
        int mid = (low + high) / 2;
        long long int check = 1;
        int flag = 0;
        for(int i = 0;i < n;i++) {
            check = check * mid;
            if(check > m) {
                flag = 1;break;
            }
        }
        if((check == m) && !flag) return mid;
        if(flag || check > m) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    cout << NthRoot(9,262144) << endl;
}