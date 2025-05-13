class Solution {
public:

    int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<int>freq(26,0);
        for(int i = 0;i < n;i++) {
            freq[s[i] - 'a']++;
        }

        for(int i = 0;i < t;i++) {
            vector<int>next(26,0);
            next[0] = freq[25];
            next[1] = (freq[25] + freq[0]) % mod;

            for(int j = 2;j <= 25;j++) {
                next[j] = freq[j - 1];
            }
            freq = next;
        }

        int answer = 0;
        for(int i = 0;i < 26;i++) {
            answer = (answer + freq[i]) % mod;
        }
        return answer;
    }
};
