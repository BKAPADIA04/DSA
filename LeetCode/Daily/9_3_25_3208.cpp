class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0;i < k-1;i++) nums.push_back(nums[i]);
        int n = nums.size();

        int left = 0;
        int right = 1;
        while(right < n) {
            if(nums[right] == nums[right-1]) {
                left = right;
            }
            else {
                if(right - left + 1 == k) {
                    ans++;
                    left++;
                }
            }
            right++;
        }
        
        return ans;
    }
};

/*
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int length = colors.size();
        int result = 0;
        // Tracks the length of the current alternating sequence
        int alternatingElementsCount = 1;
        int lastColor = colors[0];

        // Loop through the array, including the wrap-around (circular check)
        for (int i = 1; i < length + k - 1; i++) {
            // Use modulo to handle circular traversal
            int index = i % length;

            // Check if current color is the same as last color
            if (colors[index] == lastColor) {
                // Pattern breaks, reset sequence length
                alternatingElementsCount = 1;
                lastColor = colors[index];
                continue;
            }

            // Extend alternating sequence
            alternatingElementsCount += 1;

            // If sequence length reaches at least k, count it
            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
        }

        return result;
    }
};*/
