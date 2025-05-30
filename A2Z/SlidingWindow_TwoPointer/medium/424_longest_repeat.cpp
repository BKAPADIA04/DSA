class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxi = 0;
        int maxFreq = 0;
        // length of substring - maxFreq <= k is validity condition
        vector<int>freq(26,0);
        while(right < n) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq,freq[s[right] - 'A']);
            if((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
                // for(int i = 0;i < 26;i++) {
                //     maxFreq = max(maxFreq,freq[i]);
                // }
            }
            maxi = max(maxi,right - left + 1);
            right++;
        }
        return maxi;
    }
};
