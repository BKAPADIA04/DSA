#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        int ele;int count = 0;
        for(int i = 0;i < n;i++) {
            if(count == 0) {
                ele = nums[i];
                count++;
            }
            else {
                if(nums[i] == ele) count++;
                else count --;
            }
        }
    return ele;
    }
};

int main() {
    int arr[] = {2,2,1,1,1,2,2};
    int n = sizeof(arr)/sizeof(int);
    vector<int>nums(arr,arr + n);
}