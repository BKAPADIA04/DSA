class Solution {
public:

    vector<vector<vector<int>>>dp;

    int check(vector<int>&nums, int index, int prev, int tight) {
        if(index == nums.size()) return 0;

        if(dp[index][prev + 1][tight] != -1) return dp[index][prev + 1][tight];

        int take = 0; int notTake = 0;

        notTake = check(nums,index + 1,prev,tight);

        if(prev == -1) {
            take = max(take, 1 + check(nums,index + 1, index, tight));
        }

        if(prev != -1) {
            if(tight == 1) {
                if(nums[index] < nums[prev]) {
                    take = max(take, 1 + check(nums, index + 1, index, 1 - tight));
                }
            }   
            else {
                if(nums[index] > nums[prev]) {
                    take = max(take, 1 + check(nums, index + 1, index, 1 - tight));
                }
            }
        }

        return dp[index][prev + 1][tight] = max(take,notTake);
    }

    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        if(nums.size() == 2) {
            if(nums[0] == nums[1]) return 1;
            return 2;
        }

        dp = vector<vector<vector<int>>>(nums.size(),vector<vector<int>>(nums.size() + 1, vector<int>(2,-1)));

        int ans1 = check(nums,0,-1,0);
        int ans2 = check(nums,0,-1,1);

        return max(ans1,ans2);
    }   
};
