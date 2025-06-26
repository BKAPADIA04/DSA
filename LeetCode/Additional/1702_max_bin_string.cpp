class Solution {
public:
    string maximumBinaryString(string s) {
        int n = s.size();
        int start = 0;
        for(int i = 0;i < n;i++) {
            if(s[i] == '0') break;
            start++;
        }

        int zeroes = 0; int ones = 0;
        for(int i = start;i < n;i++) {
            if(s[i] == '0') zeroes++;
            else ones++;
        }

        string ans = "";
        for(int i = 0;i < start;i++) ans += '1';
        for(int i = 0;i < zeroes - 1;i++) ans += '1';
        if(zeroes > 0) ans += '0';
        for(int i = 0;i < ones;i++) ans += '1';
        return ans;
    }
};
