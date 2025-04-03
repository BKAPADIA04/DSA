class Solution {
public:

    vector<int>dp;
    int n;
    int check(int index,vector<int>&nums,int k) {
        if(index == n - 1) return nums[n - 1];
        if(dp[index] != -1e9) return dp[index];
        int maxi = INT_MIN;
        for(int i = 1;i <= k;i++) {
            int newIndex = index + i;
            newIndex = min(n - 1, newIndex);
            maxi = max(maxi,nums[index] + check(newIndex,nums,k));
        }
        return dp[index] = maxi;
    }

    // int maxResult(vector<int>& nums, int k) {
    //     n = nums.size();
    //     dp = vector<int>(n,-1e9);

    //     // dp = vector<int>(n,0);
    //     dp[n-1] = nums[n-1];
    //     multiset<int>s;
    //     s.insert(dp[n-1]);
    //     for(int i = n - 2;i >= 0;i--) {
    //         if (i + k + 1 < n) {
    //             s.erase(s.find(dp[i + k + 1]));
    //         }
    //         dp[i] = *rbegin(s) + nums[i];
    //         s.insert(dp[i]);
    //     }
    //     return dp[0];
    //     // return check(0,nums,k);
    // }


    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        dp = vector<int>(n,-1e9);
        deque<int>dq;
        dq.push_back(n - 1);
        dp[n - 1] = nums[n - 1];
        for(int i = n - 2;i >= 0;i--) {
            if (dq.front() > i + k) {
                dq.pop_front();
            }
            dp[i] = dp[dq.front()] + nums[i];
            while(!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[0];
    }
};
