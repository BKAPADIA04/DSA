#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int>left(n,0),right(n,0);
    stack<pair<int,int>> st; // Monotonic Stack

    int sum = 0;
    int mod = 1e9+7;
    for(int i = 0;i < n;i++) {
        int count = 1;
        while (!st.empty() && st.top().first > arr[i])
        {
            count += st.top().second;
            st.pop();
        }
        st.push({arr[i],count});
        left[i] = count;
    }        
    while (!st.empty())
    {
        st.pop();
    }
    for(int i = n-1;i >= 0;i--) {
        int count = 1;
        while (!st.empty() && st.top().first >= arr[i])
        {
            count += st.top().second;
            st.pop();
        }
        st.push({arr[i],count});
        right[i] = count;
    }     

    for(int i = 0;i < n;i++) {
        sum = (sum + (arr[i] * (long long)(left[i] * right[i]) % mod) % mod) % mod;
    }

    return sum;
}

int main() {
    // vector<int>nums = {3,1,2,4};
    vector<int>nums = {2,2};
    cout << sumSubarrayMins(nums) << endl;
}