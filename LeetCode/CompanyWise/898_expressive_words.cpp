class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int n = s.size();
        int answer = 0;
        for(int k = 0;k < words.size();k++) {
            int i = 0; int j = 0;
            string word = words[k];
            
            while(i < s.size() && j < word.size()) {
                if(s[i] != word[j])  { break; }
                int len1 = 1; int len2 = 1;
                
                while(i + 1 < s.size() && s[i] == s[i+1]) {
                    i++;
                    len1++;
                }

                while(j + 1 < word.size() && word[j] == word[j+1]) {
                    j++;
                    len2++;
                }

                if(len2 > len1 || (len2 < len1 && len1 < 3)) {
                    break;
                }
                i++;
                j++;
            }
            if(i == s.size() && j == word.size()) answer++;
        }
        return answer;
    }
};
