class Solution {
public:

    string s;
    int n;
    vector<int>dp;

    bool balanceCheck(vector<int>&freq) {
        int check = -1;
        for(int i = 0;i < 26;i++) {
            if(freq[i] == 0) continue;
            if(freq[i] > 0 && check == -1) {
                check = freq[i];
            }
            else if(freq[i] > 0) {
                if(freq[i] != check) return false;
            }
        }
        return true;
    }

    int check(int index) {
        if(index == n) return 0;
        if(dp[index] != -1) return dp[index];
        int ans = n;
        vector<int>freq(26,0);
        for(int j = index;j < n;j++) {
            freq[s[j] - 'a']++;
            if(balanceCheck(freq)) {
                ans = min(ans, 1 + check(j + 1));
            }
        }
        return dp[index] = ans;
    }

    int minimumSubstringsInPartition(string str) {
        s = str;
        n = s.size();
        dp = vector<int>(n,-1);
        return check(0);
    }
};
