class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.size();
        int answer = 0; char ch = '\0';
        for(int i = 0;i < n;i++) {
            if(answer == 0) {
                ch = s[i];
                answer++;
                continue;
            }
            if(s[i] == ch) answer++;
            else answer--;
        }
        return answer;
    }
};
