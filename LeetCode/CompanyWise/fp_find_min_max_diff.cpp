#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findMinMaxDifference(vector<int> arr, int k) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    deque<int>dq;
    k = n - k;
    vector<int>nums;
    nums.push_back(-1);
    for(int i = 1;i < n;i++) {
      nums.push_back(arr[i] - arr[i - 1]);
    }

    int ans = INT_MAX;
    for(int i = 0;i < nums.size();i++) {
      
      while(!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }

      dq.push_back(i);
      
      if(!dq.empty() && dq.front() == (i - k)) dq.pop_front();

      if(i >= (k-1)) ans = min(ans,nums[dq.front()]);
    }
    return ans;
  }
};
