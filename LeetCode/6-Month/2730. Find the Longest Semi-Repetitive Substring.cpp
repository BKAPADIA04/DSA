class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int i = 0; int j = 1; int last = 0;
        int maxLen = 1;
        while(j < n) {  
            if(s[j] == s[j-1]) {
                if(last) i = last;
                last = j;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};
