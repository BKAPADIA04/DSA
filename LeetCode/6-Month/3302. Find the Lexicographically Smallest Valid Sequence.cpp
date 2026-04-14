class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int>last(n,-1);
        for(int i = m - 1, j = n - 1;i >= 0 && j >= 0;i--) {
            if(word1[i] == word2[j]) {
                last[j] = i; 
                j--;
            }
        }

        vector<int>answer;
        int cnt = 0;
        for(int i = 0, j = 0; i < m;i++) {
            bool flg1 = (word1[i] == word2[j]);
            bool flg2 = (cnt == 0 && ((j == n - 1) || (i < last[j+1])));
            if(flg1 || flg2) {
                answer.push_back(i);
                cnt += (word1[i] != word2[j]);
                j++;
            }

            if(j == n) break;
        }

        if(answer.size() != n) return {};
        return answer;
    }
};
