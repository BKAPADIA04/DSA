#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int length = m + n;
        int gap = (length / 2) + (length % 2);
        while(gap > 0) {
            int left = 0;int right = left + gap;
            while(right < length) {
                if(left < m  && right >= m) // left in nums1 and right in nums2
                {
                    if(nums1[left] > nums2[right - m]) swap(nums1[left],nums2[right - m]);
                }
                else if(left >= m) // Both in nums2
                {
                    if(nums2[left - m] > nums2[right - m]) swap(nums2[left - m],nums2[right - m]);
                }
                else // Both in nums1
                {
                    if(nums1[left] > nums1[right]) swap(nums1[left],nums1[right]);
                }
                left++;right++;
            }
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        for(int i = 0;i < n;i++) {
            nums1[i+m] = nums2[i];
        }
    }
};