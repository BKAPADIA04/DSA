#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<ll>preMin;
vector<ll>sufMin;

int main() {
    // int n = 6;
    // vector<ll>nums = {-3,4,-5,2,6,-5};
    int n = 4;
    vector<ll>nums = {1,2,1,-5};
    preMin = vector<ll>(n,0);
    
    preMin[0] = nums[0];
    for(int i = 1;i < n;i++) {
        preMin[i] = min(nums[i],preMin[i - 1] + nums[i]);
    }
    sufMin = vector<ll>(n+1,0);
    ll sum = 0ll;
    for(int i = n-1;i >= 0;i--) {
        sum = sum + nums[i];
        sufMin[i] = min(sufMin[i + 1],sum);
    }

    ll mini = INT_MAX;
    for(ll i = 0;i < n;i++) {
        cout << preMin[i] << " " << sufMin[i+1] << endl;
        mini = min(mini, preMin[i] + sufMin[i+1]);
    }

    // cout << check(nums) << endl;
    ll tot = accumulate(nums.begin(),nums.end(),0ll);
    cout << tot - 2 * mini << endl;
}
