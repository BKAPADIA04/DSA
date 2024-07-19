#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {  
    map<int,int>preSum;
    int count = 0;

    int n = nums.size();
    int sum = 0;
    preSum[0] = 1;

    for(int i = 0;i < n;i++) {
        sum += nums[i];
        if(preSum.find(sum - goal) != preSum.end()) {
            count += preSum[sum - goal];
        }
        preSum[sum]++;
    }

    return count;
}


int atMost(vector<int>& nums,int k){
    int n = nums.size();
    int i=0,j=0;
    int cnt=0,ans=0;

    while(j<n){
        cnt += nums[j]==1;
        while(i<=j&&cnt>k){
            cnt -= nums[i]==1;
            i++;
        }
        ans += j-i+1;
        j++;
    }
    return ans;
}

int numSubarraysWithSum_(vector<int>& nums, int goal) {
    return atMost(nums,goal)-atMost(nums,goal-1);
}

int main() {
    vector<int>nums = {1,0,1,0,1};
    cout << numSubarraysWithSum(nums,2) << endl;
    cout << numSubarraysWithSum_(nums,2) << endl;
}
