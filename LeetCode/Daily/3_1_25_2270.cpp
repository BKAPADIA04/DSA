class Solution {
public:

    void print(vector<long long>nums) {
        for(auto it:nums) cout << it << " ";
        cout << endl;
    }

    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>preSum(n+1,0);
        vector<long long>sufSum(n+1,0);

        for(int i = 1;i <= n;i++) {
            preSum[i] = preSum[i-1] + nums[i-1] * 1ll;
        }

        for(int i = n - 1;i >= 0;i--) {
            sufSum[i] = sufSum[i+1] + nums[i] * 1ll;
        } 

        int ans = 0;
        for(int i = 0;i < n-1;i++) {
            if(preSum[i+1] >= sufSum[i+1]) ans++;
        }
        print(preSum); print(sufSum);
        return ans;

    }
};

/* class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Keep track of sum of elements on left and right sides
        long long leftSum = 0, rightSum = 0;

        // Initially all elements are on right side
        for (int num : nums) {
            rightSum += num;
        }

        int count = 0;
        // Try each possible split position
        for (int i = 0; i < nums.size() - 1; i++) {
            // Move current element from right to left side
            leftSum += nums[i];
            rightSum -= nums[i];

            // Check if this creates a valid split
            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};*/
