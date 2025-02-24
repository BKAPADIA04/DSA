// class Solution {
// public:
//     void print(vector<bool>v) {
//         for(auto it:v) cout << it << " ";
//         cout << endl;
//     }

//     bool check(vector<int>&nums,vector<bool>&pre,vector<bool>&suf,int mid) {
//         int n = nums.size();
//         for(int i = 0;i < n;i++) {
//             if(i == 0) {
//                 if(suf[mid]) return true;
//                 continue;
//             }
//             int j = i + mid;
//             if(j > n) break;
//             if(j == n) {
//                 if(pre[i-1]) return true;
//                 continue;
//             }
//             if(pre[i-1] && suf[j] && nums[i-1] <= nums[j]) return true;
//         }
//         return false;
//     }

//     int findLengthOfShortestSubarray(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool>pre(n,false); pre[0] = true;
//         for(int i = 1;i < n;i++) {
//             if(nums[i] >= nums[i-1]) pre[i] = true;
//             else break;
//         }

//         vector<bool>suf(n,false); suf[n - 1] = true;
//         for(int i = n - 2;i >= 0;i--) {
//             if(nums[i] <= nums[i+1]) suf[i] = true;
//             else break;
//         }

//         // print(pre); print(suf);
//         int low = 0; int high = n; int ans = n;
//         while(low <= high) {
//             int mid = (low + high)/2;
//             if(check(nums,pre,suf,mid)) {
//                 ans = mid;
//                 high = mid - 1;
//             }
//             else low = mid + 1;
//         }
//         return ans;
//     }
// };

// Another nlogn Approach
/*class Solution {
private:
    int helperBinarySearch(vector<int>& arr, int left, int right, int target) {
        // Find the first index where arr[mid] >= target
        // finding lowerbound
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;

        // Find the longest non-decreasing subarray from the left
        while (left + 1 < n && arr[left] <= arr[left + 1]) left++;

        // Find the longest non-decreasing subarray from the right
        while (right - 1 >= 0 && arr[right] >= arr[right - 1]) right--;

        // If the entire array is already sorted
        if (left >= right) return 0;

        // Start with removing either left or right part completely
        int ans = min(n - (left + 1), right);

        // Try to merge the left and right parts
        for (int i = 0; i <= left; i++) {
            int target = arr[i];
            int j = helperBinarySearch(arr, right, n, target);
            ans = min(ans, j - (i + 1));
        }

        return ans;
    }
};*/

// N Approach
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right = arr.size() - 1;
        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }

        int ans = right;
        int left = 0;
        while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
            // find next valid number after arr[left]
            while (right < arr.size() && arr[left] > arr[right]) {
                right++;
            }
            // save length of removed subarray
            ans = min(ans, right - left - 1);
            left++;
        }
        return ans;
    }
};
