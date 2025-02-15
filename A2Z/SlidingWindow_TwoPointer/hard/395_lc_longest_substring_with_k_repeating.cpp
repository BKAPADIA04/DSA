class Solution {
public:

    int check(string s,int k,int window) {
        int left = 0; int right = 0; int n = s.size(); int win = 0; int count = 0; int ans = 0;
        vector<int>freq(26,0);
        while(right < n) {
            freq[s[right] - 97]++;

            if(freq[s[right] - 97] == 1) win++;
            if(freq[s[right] - 97] == k) count++;

            while(left <= right && win > window) {
                if(freq[s[left] - 97] == k) count--;
                freq[s[left] - 97]--;
                if(freq[s[left] - 97] == 0) win--;
                left++;
            }

            
            if(count == win)
                ans = max(ans,right - left + 1);
            right++;
        }
        return ans;
    }

    int longestSubstring(string s, int k) {
        int n = s.size(); 
        int uniques = 0; // i was struggling with deciding kab tak window jaayega
        // i number of unique characters tak ka window lelo
        vector<int>freq(26,0);
        for(int i = 0;i < n;i++) {
            if(freq[s[i] - 97] == 0) uniques++;
            freq[s[i] - 97]++;
        }

        int ans = 0;
        for(int i = 1;i <= uniques;i++) {
            cout << i << " " << check(s,k,i) << endl;
            ans = max(ans,check(s,k,i));
        }
        return ans;
    }
};
