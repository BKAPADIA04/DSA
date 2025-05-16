class Solution {
public:

    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            diff += (s1[i] != s2[i] ? 1 : 0);
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int>dp(n,1);
        vector<int>prev(n,-1);

        int maxIndex = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < i;j++) {
                if(check(words[i],words[j]) && groups[i] != groups[j] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
        }

        for(int i = 0;i < n;i++) {
            if(dp[i] > dp[maxIndex]) maxIndex = i;
        }

        vector<string>answer;
        for(int i = maxIndex; i >= 0; i = prev[i]) {
            answer.push_back(words[i]);
        }

        reverse(answer.begin(),answer.end());
        return answer;
    }
};
