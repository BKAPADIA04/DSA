class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int answer = n;

        for(int i = 0;i < n;i++) {
            // odd
            int low = i - 1; int high = i;
            while(low >= 0 && high < n && s[low] == s[high]) {
                answer++;
                low--;
                high++;
            }

            // even
            low = i - 1; high = i + 1;
            while(low >= 0 && high < n && s[low] == s[high]) {
                answer++;
                low--;
                high++;
            }
        }
        return answer;
    }
};
