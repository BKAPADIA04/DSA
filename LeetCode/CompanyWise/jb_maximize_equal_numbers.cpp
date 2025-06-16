#include <bits/stdc++.h>
using namespace std;

int check(int k, vector<int>&nums) {
  vector<int>arrival,departure;
  for(int i = 0;i < nums.size();i++) {
    arrival.push_back(nums[i] - k);
    departure.push_back(nums[i] + k);
  }
  
  sort(arrival.begin(),arrival.end());
  sort(departure.begin(),departure.end());
  
  int i = 1; int j = 0; int ans = 1; int count = 1;
  while(i < arrival.size() && j < departure.size()) {
    if(arrival[i] <= departure[j]) {
      count++;
      ans = max(ans,count);
      i++;
    }
    else {
      count--;
      j++;
    }
  }
  return ans;
}

int main() {
  int n;int k; cin >> n >> k;
  vector<int>nums;
  for(int i = 0;i < n;i++) {
    int ele; cin >> ele; nums.push_back(ele);
  }
  cout << check(k,nums) << endl;
  return 0;
}
