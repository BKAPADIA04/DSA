class Solution {
public:

    vector<string>dp;

    string dfs(vector<int>& cost, int target) {
        if(target < 0) return "0";
        if(target == 0) return "";

        if(dp[target] != "-1") return dp[target];

        string ans = "0";

        for(int num = 9;num >= 1;num--) {
            string temp = dfs(cost, target - cost[num-1]);
            if(temp == "0") continue;
            temp = to_string(num) + temp;
            if(ans == "0" || ans.size() < temp.size()) {
                ans = temp;
            }
        }
        return dp[target] = ans;
    }

    string largestNumber(vector<int>& cost, int target) {
        dp = vector<string>(target + 1,"-1");
        return dfs(cost, target);
    }
};
