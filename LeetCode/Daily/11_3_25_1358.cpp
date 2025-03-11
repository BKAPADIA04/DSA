class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int>freq;
        int answer = 0;
        int left = 0; int right = 0;
        while(right < n) {
            freq[s[right]]++;

            while(freq.size() >= 3) {
                answer += (n - right);
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            right++;
        }
        return answer;
    }
};
