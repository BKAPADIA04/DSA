class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        vector<int>left(n,2); vector<int>right(n,2);
        left[0] = 1; right[n-1] = 1;

        for(int i = 2;i < n;i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                left[i] = left[i-1] + 1;
            }
        }

        for(int i = n - 3;i >= 0;i--) {
            if(nums[i] - nums[i+1] == nums[i+1] - nums[i+2]) {
                right[i] = right[i+1] + 1;
            }
        }

        int answer = 2;

        for(int i = 0;i < n;i++) {
            answer = max(answer, max(left[i], right[i]));
            if(i == 0) {
                answer = max(answer, 1 + right[i+1]);
            }
            else if(i == n - 1) {
                answer = max(answer, 1 + left[i-1]);
            }
            else {
                answer = max(answer, 1 + right[i+1]);
                answer = max(answer, 1 + left[i-1]);

                if(abs(nums[i+1] - nums[i-1]) % 2 == 0) {
                    int diff = (nums[i+1] - nums[i-1])/2;
                    int leftLen = 1; int rightLen = 1;
                    if(i >= 2 && (nums[i-1] - nums[i-2] == diff)) leftLen = left[i-1];
                    if(i <= n-3 && (nums[i+2] - nums[i+1] == diff)) rightLen = right[i+1];
                    answer = max(answer, 1 + leftLen + rightLen);
                }
            }
        }
        return answer;
    }
};
