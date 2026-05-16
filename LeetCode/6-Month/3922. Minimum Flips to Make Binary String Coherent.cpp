class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<int>freq(2,0);
        for(int i = 0;i < n;i++) {
            freq[s[i] - '0']++;
        }

        if(!freq[0] || !freq[1]) return 0;
        int flag = (s.front() == s.back()) && (s.front() == '1');

        return min(freq[0], freq[1] - 1 - flag);
    }
};
