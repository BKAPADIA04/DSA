class Solution {
public:
    vector<vector<int>>dp;

    int check(vector<int>&nums, int time,int bitMask, int remainingTime) {
        int n = nums.size();
        if(bitMask == ((1 << n) - 1)) return 0;
        if(dp[bitMask][remainingTime] != -1) return dp[bitMask][remainingTime];
        int ans = n;

        for(int i = 0;i < n;i++) {
            if(((1 << i) & bitMask) != 0) continue;

            int newMask = bitMask | (1 << i);
            if(nums[i] <= remainingTime) {
                ans = min(ans, check(nums,time,newMask,remainingTime - nums[i]));
            }
            else {
                ans = min(ans, 1 + check(nums,time,newMask,time - nums[i]));
            }
        }
        return dp[bitMask][remainingTime] = ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int rows = 1 << n;
        dp = vector<vector<int>>(rows,vector<int>(sessionTime + 1,-1));
        return 1 + check(tasks,sessionTime,0,sessionTime);
    }
};
