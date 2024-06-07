#include <bits/stdc++.h>
using namespace std;
int first_posn(vector<int>& nums,int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int index = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] >= target) {
            index = mid; high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if(index != -1 && nums[index] == target) return index;
    return -1;
}

int last_posn(vector<int>& nums,int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int index = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] <= target) {
            index = mid; low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if(index != -1 && nums[index] == target) return index;
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0) return {-1,-1};
    int first = first_posn(nums,target);
    int last = last_posn(nums,target);
    return {first,last};
}


//or 

vector<int> searchRange_bound(vector<int>& nums, int target) {
    if(binary_search(nums.begin(),nums.end(),target)){
    int m = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    int n = upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;

    return {m,n};}
    return {-1,-1};
}
int main() {
    vector<int>nums = {5,7,7,8,8,10};
    vector<int>ans = searchRange(nums,8);
    cout << ans[0] << " " << ans[1] << endl;
    vector<int>ans1 = searchRange_bound(nums,8);
    cout << ans1[0] << " " << ans1[1] << endl;
    // vector<int> v{ 10, 20, 30, 30, 30, 35, 40, 50 }; 
    // cout << *lower_bound(v.begin(),v.end(),35) << endl;
    // cout << *upper_bound(v.begin(),v.end(),35) << endl;
}