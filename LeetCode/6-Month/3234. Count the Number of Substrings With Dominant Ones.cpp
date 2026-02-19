class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int>preOne(n,0);
        preOne[0] = s[0] == '1' ? 1 : 0;
        for(int i = 1;i < n;i++) preOne[i] = preOne[i-1] + ((s[i] == '1') ? 1 : 0);

        int answer = 0;

        for(int i = 0;i < n;i++) {
            for(int j = i;j < n;j++) {
                int ones = preOne[j] - ((i > 0) ? preOne[i-1] : 0);
                int zeroes = (j - i + 1) - ones;

                if((long long) zeroes * zeroes > ones) {
                    j += ((long long) zeroes * zeroes - ones - 1);
                }
                else if((long long) zeroes * zeroes == ones) {
                    answer += 1;
                }
                else {
                    answer += 1;
                    int k = sqrt(ones) - zeroes;
                    int next = j + k;
                    if(next >= n) {
                        answer += (n - j - 1);
                        break;
                    }
                    else {
                        answer += k;
                    }
                    j = next;
                }
            }
        }

        return answer;
    }
};
