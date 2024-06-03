#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int target) {
    int n = nums.size();
    map <int,int> prexor;
    int xor_sum = 0;
    int count = 0;
    for(int i = 0;i < n;i++) {
        xor_sum ^= nums[i];

        if(xor_sum == target) count++;

        int rem = xor_sum ^ target;
        if(prexor.find(rem) != prexor.end()) count += prexor[rem];

        prexor[xor_sum]++;

    }
    return count;
}
int main() {
    vector<int>v = {5, 6, 7, 8, 9};
    int n = v.size();
    cout << solve(v,5) << endl;  
}