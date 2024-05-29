#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();int index = -1;
    for(int i = n - 1;i > 0;i--) {
        if(nums[i - 1] < nums[i]) {
            index = i - 1;
            break;
        }
    }
    if(index == -1) {
        reverse(nums.begin(),nums.end());
        return;
    }
    else {
        for(int i = n - 1;i > index;i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1,nums.end());
        return;
    }
}
int main() {
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(int);
    vector<int>nums(arr,arr + n);
    nextPermutation(nums);
    for(int i = 0;i<nums.size();i++) {
        cout << nums[i] << " ";
    }

}


