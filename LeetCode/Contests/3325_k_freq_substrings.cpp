class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        // Brute Force
        // int n = s.size(); int answer = 0;
        // for(int i = 0;i < n;i++) {
        //     vector<int>freq(26);
        //     for(int j = i;j < n;j++) {
        //         freq[s[j] - 97]++;

        //         for(int l = 0;l < 26;l++) if(freq[l] >= k) { answer++; break; }
        //     }
        // }
        // return answer;

        // Optimized
        int n = s.size(); int answer = 0; vector<int>freq(26); int left = 0;
        for(int right = 0;right < n;right++) {
            freq[s[right]-'a']++;

            while(left <= right && freq[s[right]-'a'] >= k) {
                freq[s[left]-'a']--;
                left++;
            }

            answer += left;
        }
        return answer;
    }
};
