class Solution {
public:

    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int len = str.size();
        int i = len - 1; int marker = len;
        while(i >= 1) {
            int curr = str[i] - '0';
            int prev = str[i-1] - '0';
            if(prev > curr) {
                str[i-1] = str[i-1] - 1;
                marker = i;
            }
            i--;
        }

        for(i = marker;i < len;i++) {
            str[i] = '9';
        }

        return stoi(str);
    }
};
