class Solution {
public:

    int n;
    vector<int>nums;

    // unordered_map<int,unordered_map<int,int>>dp;
    vector<vector<int>>dp;

    int check(int index, int x) {
        if(index == n) return 0;
        if(nums[index] < x) return check(index + 1,x);

        // if(dp.find(index) != dp.end() && dp[index].find(x) != dp[index].end()) return dp[index][x];
        if(dp[index][x] != -1) return dp[index][x];
        
        int ans = 0;
        int temp1 = 0;
        int temp2 = check(index + 1,x);
        if(nums[index] > x) {
            temp1 = nums[index] + check(index + 1,x + nums[index]);
        }
        ans = max(temp1,temp2);

        return dp[index][x] = ans;
    }
    
    int maxTotalReward(vector<int>& reward) {
        unordered_set<int>s;
        for(auto it:reward) {
            s.insert(it);
        } 
        for(auto it : s) nums.push_back(it);
        sort(nums.begin(),nums.end());
        n = nums.size();
        dp = vector<vector<int>>(n,vector<int>(4001,-1));
        return check(0,0);
    }
};
