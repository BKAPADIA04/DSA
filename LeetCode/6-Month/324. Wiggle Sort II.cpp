
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i += 2) {
            nums[i] = pq.top();
            pq.pop();
        }
        for (int i = 0; i < n; i += 2) {
            nums[i] = pq.top();
            pq.pop();
        }
    }
};


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // Create a copy of the original array
        vector<int> sortedArray = nums;
      
        // Sort the copied array in ascending order
        sort(sortedArray.begin(), sortedArray.end());
      
        // Get the size of the array
        int arraySize = nums.size();
      
        // Initialize two pointers:
        // leftPointer: points to the middle element (for smaller half)
        // rightPointer: points to the last element (for larger half)
        int leftPointer = (arraySize - 1) / 2;
        int rightPointer = arraySize - 1;
      
        // Reconstruct the array in wiggle pattern
        // Even indices get elements from the smaller half (in reverse order)
        // Odd indices get elements from the larger half (in reverse order)
        for (int index = 0; index < arraySize; ++index) {
            if (index % 2 == 0) {
                // Even index: pick from smaller half
                nums[index] = sortedArray[leftPointer];
                leftPointer--;
            } else {
                // Odd index: pick from larger half
                nums[index] = sortedArray[rightPointer];
                rightPointer--;
            }
        }
    }
};
