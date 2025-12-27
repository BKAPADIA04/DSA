class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        // Build prefix sum array
        vector<int> prefixSum(n + 1, 0);
        int maxValue = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
            maxValue = max(maxValue, arr[i]);
        }

        auto calculateSum = [&](int value) {
            int index = upper_bound(arr.begin(), arr.end(), value) - arr.begin();
            return prefixSum[index] + (n - index) * value;
        };

        // Binary search template: find first value where sum >= target
        int left = 0;
        int right = maxValue;
        int firstTrueIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (calculateSum(mid) >= target) {  // feasible condition
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Edge case: no value produces sum >= target
        if (firstTrueIndex == -1) {
            return maxValue;
        }

        // Edge case: even value 0 produces sum >= target
        if (firstTrueIndex == 0) {
            return 0;
        }

        // Check both candidates
        if (abs(calculateSum(firstTrueIndex - 1) - target) <= abs(calculateSum(firstTrueIndex) - target)) {
            return firstTrueIndex - 1;
        }
        return firstTrueIndex;
    }
};
