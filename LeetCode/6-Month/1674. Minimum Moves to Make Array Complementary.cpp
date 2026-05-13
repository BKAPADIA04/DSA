class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int limitMax = 2 * limit + 2;
        vector<int>diff(limitMax + 1);
        int n = nums.size();

        for(int i = 0;i < n / 2;i++) {
            int a = nums[i]; int b = nums[n - i - 1];
            int sum = a + b;

            int mini = min(a,b) + 1;
            int maxi = max(a,b) + limit;

            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            diff[mini] -= 1;
            diff[maxi + 1] += 1;

            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        vector<int>preSumArr; int preSum = 0;
        int ans = n; 
        for(int i = 2;i <= limit * 2;i++) {
            preSum += diff[i];
            ans = min(ans, preSum);
        }
        return ans;
    }   
};
