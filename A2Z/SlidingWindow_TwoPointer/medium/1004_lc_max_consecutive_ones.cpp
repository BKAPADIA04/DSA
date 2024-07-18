#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0,right = 0;
    int maxlen = 0;
    while(right < n) {
            if (nums[right] == 0) {
                k--;
            }

            while (k < 0) {
                if (nums[left] == 0) {
                    k++;
                }
                left++;
            }
            // if(k == 0) {
            //     while(left <= right && nums[left] != 0) left++;
            //     left++;
            // }
            // else k--;
        maxlen = max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}


int main() {
    vector<int>nums = {1,1,0,1,0,1,1,1};
    cout << longestOnes(nums,2) << endl;

    vector<int>temp = {1,1,1,0,0,0,1,1,1,1,0};
    cout << longestOnes(temp,2) << endl;

    vector<int>temp1 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << longestOnes(temp1,3) << endl;


}