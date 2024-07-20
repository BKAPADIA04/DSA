#include <bits/stdc++.h>
using namespace std;

int subarraywithAtmostKDistinct(vector<int>& nums, int k) {
    if(k < 0) return 0;
    int temp_k = k;
    map<int,int>freq_map;
    int n = nums.size();
    int left = 0;int right = 0;
    int count = 0;
    while(right < n) {
        if(freq_map.find(nums[right]) == freq_map.end()) {
            k--;
        }
        freq_map[nums[right]]++;

        while(k < 0) {
            freq_map[nums[left]]--;
            if(freq_map[nums[left]] == 0) {
                freq_map.erase(nums[left]);
                k++;
            }
            left++;
        }
        count += (right-left+1);
        right++;
    }
    return count;
}


int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subarraywithAtmostKDistinct(nums,k) - subarraywithAtmostKDistinct(nums,k-1);
}

int main() {
    vector<int>nums = {1,2,1,3,4};
    int k = 3;
    cout << subarraysWithKDistinct(nums,k) << endl;
}
