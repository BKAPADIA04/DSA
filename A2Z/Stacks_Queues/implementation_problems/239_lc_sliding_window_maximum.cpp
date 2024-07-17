#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int>dq;
    vector<int>answer;
    for(int i = 0;i < n;i++) {
        if(!dq.empty() && dq.front() == (i-k)) dq.pop_front();

        while(!dq.empty() && nums[i] > nums[dq.front()]) dq.pop_back();

        dq.push_back(i);

        if(i >= k-1) answer.push_back(nums[dq.front()]);
    }   
    return answer;     
}

int main() {
    vector<int>nums {4,0,-1,3,5,3,6,8};
    int k = 3;
    vector<int>answer = maxSlidingWindow(nums,k);
    for (int i:answer) cout << i << " ";
    cout << endl;
}