#include <bits/stdc++.h>
using namespace std;

int check(vector<int>&nums,int k) {
    int n = nums.size();
    vector<int>answer;
    int ans = INT_MIN;
    deque<int>dq;
    for(int i = 0;i < n;i++) {
        if(!dq.empty() && dq.front() == i - k) dq.pop_front();

        while(!dq.empty() && nums[i] < nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if(i >= k - 1) { ans = max(nums[dq.front()],ans); answer.push_back(nums[dq.front()]);}
    }
    // for(auto it:answer) cout << it << " ";
    return ans;
}

int main() {
    vector<int>nums = {1,3,-1,-3,5,3,6,7}; int k = 3;
    cout <<  check(nums,k) << endl;
}
