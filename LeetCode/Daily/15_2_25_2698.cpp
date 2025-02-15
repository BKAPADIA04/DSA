class Solution {
public:

    int check(vector<vector<int>>&dp,int start,int sum,int target,string num) {
        if(start == num.size()) {
            return sum == target;
        }
        if(sum > target) return false;

        if(dp[start][sum] != -1) return dp[start][sum];

        bool possible = false;

        for(int curr = start;curr < num.size();curr++) {
            string temp = num.substr(start,curr - start + 1);
            int sumi = stoi(temp);
            possible = possible || check(dp,curr+1,sum + sumi,target,num);
        }
        return dp[start][sum] = possible;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            int tempo = i * i;
            string num = to_string(tempo);
            vector<vector<int>>dp(num.size()+1,vector<int>(i+1,-1));
            if(check(dp,0,0,i,num)) {
                ans += tempo;
            }
        }
        return ans;
    }
};
