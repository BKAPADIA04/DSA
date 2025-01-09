class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int answer = 0;

        for(int i = 0;i < words.size();i++) {
            for(int j = i+1;j < words.size();j++) {
                if(i != j) {
                    int i_size = words[i].size();
                    int j_size = words[j].size();
                    if(words[j].substr(0,i_size) == words[i] && words[j].substr(j_size-i_size) == words[i]) {
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
};