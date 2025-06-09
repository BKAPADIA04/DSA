class Solution {
public:

    int mod = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int>ms;
        vector<int>dp(n+1);
        vector<int>preSum(n+1);
        dp[0] = preSum[0] = 1;

        int left = 0;
        for(int right = 1;right <= n;right++) {
            ms.insert(nums[right - 1]);
            while(*ms.rbegin() - *ms.begin() > k) {
                ms.erase(ms.find(nums[left]));
                left++;
            }
            dp[right] = (preSum[right - 1] - ((left - 1 >= 0) ? preSum[left - 1] : 0) + mod) % mod;
            preSum[right] = (preSum[right - 1] + dp[right]) % mod;
        }
        return dp[n];
    }
};

/*    int countPartitions(vector<int>& A, int k) {
        int n = A.size(), mod = 1e9 + 7, acc = 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        deque<int> minq, maxq;
        for (int i = 0, j = 0; j < n; ++j) {
            while (!maxq.empty() && A[j] > A[maxq.back()])
                maxq.pop_back();
            maxq.push_back(j);
            while (!minq.empty() && A[j] < A[minq.back()])
                minq.pop_back();
            minq.push_back(j);
            while (A[maxq.front()] - A[minq.front()] > k) {
                acc = (acc - dp[i++] + mod) % mod;
                if (minq.front() < i)
                    minq.pop_front();
                if (maxq.front() < i)
                    maxq.pop_front();
            }

            dp[j + 1] = acc;
            acc = (acc + dp[j + 1]) % mod;
        }
        return dp[n];
    }*/
