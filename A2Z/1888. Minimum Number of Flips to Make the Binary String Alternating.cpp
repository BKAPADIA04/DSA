class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int i = 0; int j = 0;
        int flip1 = 0; int flip2 = 0;
        int answer = n/2;
        while(j < 2 * n) {
            char ch1 = ((j % 2 == 0) ? '0' : '1');
            char ch2 = ((j % 2 == 0) ? '1' : '0');

            if(s[j % n] != ch1) {
                flip1++;
            }
            if(s[j % n] != ch2) {
                flip2++;
            }

            if((j - i + 1) > n) {
                char ch1i = ((i % 2 == 0) ? '0' : '1');
                char ch2i = ((i % 2 == 0) ? '1' : '0');

                if(s[i % n] != ch1i) {
                    flip1--;
                }

                if(s[i % n] != ch2i) {
                    flip2--;
                }

                i++;
            }

            if((j - i + 1) == n) {
                answer = min(answer, min(flip1,flip2));
            }

            j++;
        }

        return answer;
    }
};
