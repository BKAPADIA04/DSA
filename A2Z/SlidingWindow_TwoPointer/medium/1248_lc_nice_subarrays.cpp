#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int answer = 0;
    map<int,int>oddMap;  oddMap[0] = 1;
    int right = 0;
    int odd_count = 0;
    while(right < nums.size()) {
        if(nums[right] & 1) odd_count++;
        if(oddMap.find(odd_count-k) != oddMap.end()) {
            answer += oddMap[odd_count-k];
        }
        oddMap[odd_count]++;
        right++;
    }
    return answer;
}

int func(vector<int> &nums,int k){
    if(k<0)
        return 0;
        
    int l = 0;
    int r = 0;
    int sum = 0;
    int n = nums.size();
    int cnt = 0;
    while(r<n){
        sum += (nums[r]%2);
        while(sum>k){
            sum = sum - (nums[l]%2);
            l++;
        }
        cnt = cnt + (r-l+1);
        r++;
    }
    return cnt;
}
int numberOfSubarrays_(vector<int>& nums, int k) {
    return func(nums,k) - func(nums,k-1);
}

int main() {
    // vector<int>nums = {2,2,2,1,2,2,1,2,2,2};
    vector<int>nums = {1,1,2,1,1};
    cout << numberOfSubarrays(nums,3) << endl;
    cout << numberOfSubarrays_(nums,3) << endl;
}