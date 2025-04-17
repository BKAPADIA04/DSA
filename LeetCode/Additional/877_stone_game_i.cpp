class Solution {
public:

    vector<vector<vector<int>>>dp;

    int check(vector<int>&nums,int i, int j, int chance) {
        if(i > j) return 0;

        if(dp[i][j][chance] != -1) return dp[i][j][chance];
        int ans;

        int temp1,temp2;
        if(chance == 1) {
            temp1 = nums[i] + check(nums,i + 1, j, 1 - chance);
            temp2 = nums[j] + check(nums,i, j - 1, 1 - chance);
            ans = max(temp1,temp2);
        }
        else {
            temp1 = -nums[i] + check(nums,i + 1, j, 1 - chance);
            temp2 = -nums[j] + check(nums,i, j - 1, 1 - chance);
            ans = min(temp1,temp2);
        }

        return dp[i][j][chance] = ans;
    }

    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return check(nums,0,n-1,1);
    }
};


/*class Solution {
public:
   int dp[555][555];
    int solve(int i, int j, vector<int>& nums) {
        // base case
        if (i > j)
            return 0;

        if (i == j)
            return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = nums[i] + min(solve(i + 2, j,nums), solve(i + 1, j - 1,nums));
        int right = nums[j] + min(solve(i, j - 2,nums), solve(i + 1, j - 1,nums));
        dp[i][j] = max(left, right);
        return dp[i][j];
    }
    bool stoneGame(vector<int>& nums) {
                int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int totalscore = accumulate(nums.begin(),nums.end(),0);
        int player1skore=solve(0,n-1,nums);
        int player2skore = totalscore-player1skore;
        if(player1skore==player2skore || player1skore>player2skore)return true;
        else return false;
    }
};*/
