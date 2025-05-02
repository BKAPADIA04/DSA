class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int>sufA(n,0);
        vector<int>preB(n,0);
        for(int i = n - 2;i >= 0;i--) {
            sufA[i] = sufA[i + 1] + (s[i + 1] == 'a' ? 1 : 0);
        }

        for(int i = 1;i < n;i++) {
            preB[i] = preB[i - 1] + (s[i - 1] == 'b' ? 1 : 0);
        }

        int ans = n;
        for(int i = 0;i < n;i++) {
            ans = min(ans,sufA[i] + preB[i]);
        }
        return ans;
    }
};

/*class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int min_deletions = 0;
        int b_count = 0;

        // min_deletions variable represents dp[i]
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                b_count++;
            } else {
                // Two cases: remove 'a' or keep 'a'
                min_deletions = min(min_deletions + 1, b_count);
            }
        }

        return min_deletions;
    }
};*/
