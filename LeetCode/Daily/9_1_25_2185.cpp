class Solution {
public:

    bool kmp(string s,int check_size) {
        vector<int>lps(s.size());

        for(int i = 1;i < s.size();i++) {
            int prev_index = lps[i-1];

            while(prev_index > 0 && s[prev_index] != s[i]) prev_index = lps[prev_index-1];

            lps[i] = prev_index + (s[i] == s[prev_index]);


            int index = i - 2*check_size;
            if(lps[i] == check_size && index == 0) return true;
        }
        return false;
    }

    int prefixCount(vector<string>& words, string pref) {
        int answer = 0;
        for(int i = 0;i < words.size();i++) {
            string s = pref + "#" + words[i];
            answer += kmp(s,pref.size());
        }
        return answer;
    }
};