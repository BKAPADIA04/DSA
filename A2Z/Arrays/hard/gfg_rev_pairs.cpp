#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&nums,int low,int mid,int high) {
    int n = nums.size();
    int left = low; int right = mid + 1;
    vector<int>temp;int count = 0;
    while(left <= mid && right <= high) {
        if(nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left <= mid) { temp.push_back(nums[left]); left++; }
    while(right <= high) { temp.push_back(nums[right]); right++; }

    for(int i = low;i <= high;i++) {
        nums[i] = temp[i - low];
    }
} 

int rev_pairs(vector<int>&nums,int low,int mid,int high) {
    int count = 0;
    int n = nums.size();
    int right = mid + 1;
    for(int i = low;i <= mid;i++) {
        while((right <= high) && (nums[i] > (2LL * nums[right]))) right++;
        count += (right - (mid + 1));
    }   
    return count;
}

int mergeSort(vector<int>&nums,int low,int high) {
    int count = 0;
    if(low >= high) return count; 
    int mid = (low + high)/2;
    count += mergeSort(nums,low,mid);
    count += mergeSort(nums,mid + 1,high);
    count += rev_pairs(nums,low,mid,high);
    merge(nums,low,mid,high);
    return count;
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    return mergeSort(nums,0,n - 1);
}

int main() {
    vector<int> a = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    int n = 5;
    int cnt = reversePairs(a);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}