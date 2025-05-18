class Solution {
public:

    vector<string>columnStates;
    int mod = 1e9 + 7;

    void generateColumnStates(string curr, char prev, int i, int m) {
        if(i == m) {
            columnStates.push_back(curr);
            return;
        }

        for(char ch:{'R','G','B'}) {
            if(ch == prev) continue;
            generateColumnStates(curr + ch, ch, i + 1,m);
        }
    }

    vector<vector<int>>dp;

    int solve(int remCols, int prevIndex) {
        if(remCols == 0) return 1;

        if(dp[remCols][prevIndex] != -1) return dp[remCols][prevIndex];

        int ways = 0;
        string prevState = columnStates[prevIndex];
        int m = prevState.size();

        for(int i = 0;i < columnStates.size();i++) {
            if(i == prevIndex) continue;
            string currState = columnStates[i];

            bool valid = true;
            for(int j = 0;j < m;j++) {
                if(prevState[j] == currState[j]) {
                    valid = false; break;
                }
            }
            if(valid) {
                ways = (ways + solve(remCols - 1,i)) % mod;
            }
        }
        return dp[remCols][prevIndex] = ways;
    }

    int colorTheGrid(int m, int n) {
        generateColumnStates("",'#',0,m);
        
        int ans = 0;
        dp = vector<vector<int>>(n,vector<int>(columnStates.size(),-1));
        for(int i = 0;i < columnStates.size();i++) {
            ans = (ans + solve(n - 1, i)) % mod;
        }

        return ans;
    }
};
