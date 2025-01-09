class Solution {
public:

    bool kmp(string s,int check_size) {
        vector<int>lps(s.size());

        for(int i = 1;i < s.size();i++) {
            int prev_index = lps[i-1];

            while(prev_index > 0 && s[prev_index] != s[i]) prev_index = lps[prev_index-1];

            lps[i] = prev_index + (s[i] == s[prev_index]);

            if(lps[i] == check_size) return true;
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        for(int i = 0;i < words.size();i++) {
            for(int j = 0;j < words.size();j++) {
                if(i != j) {
                    string s = words[i] + "#" + words[j];
                    if(kmp(s,words[i].size())) {
                        ans.push_back(words[i]); break;
                    }
                }
            }
        }
        return ans;
    }
};