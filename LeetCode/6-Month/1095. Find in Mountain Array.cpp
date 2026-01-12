/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int n;

    int findPeak(MountainArray &mountainArr) {
        int low = 1; int high = n - 2;

        while(low <= high) {
            int mid = (low + high)/2;
            int midElement = mountainArr.get(mid);
            int nextElement = mountainArr.get(mid+1);
            int prevElement = mountainArr.get(mid-1);
            if(midElement > prevElement && midElement > nextElement) return mid;
            if(midElement > prevElement) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    int binarySearch(MountainArray &mountainArr, int target, int low, int high,bool flag) {
        while(low <= high) {
            int mid = (low + high)/2;
            int midElement = mountainArr.get(mid);
            if(midElement == target) return mid;
            if(flag) {
                if(target > midElement) low = mid + 1;
                else high = mid - 1;
            }
            else {
                if(target < midElement) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        n = mountainArr.length();
        int mid = findPeak(mountainArr);
        if(mountainArr.get(mid) == target) return mid;
        int lower = binarySearch(mountainArr, target, 0, mid - 1,true);
        if(lower != -1) return lower;
        int upper = binarySearch(mountainArr, target, mid + 1, n - 1,false);
        if(upper != -1) return upper;
        return -1;
    }
};
