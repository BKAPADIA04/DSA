class Solution {
public:
    string mergeCharacters(string s, int k) {
        vector<stack<int>>st(26);
        string answer; int n = s.size();
        for(int i = 0;i < n;i++) {
            int idx = answer.size();
            int ch = s[i] - 'a';
            if(!st[ch].empty() && ((idx - st[ch].top()) <= k)) {
                continue;
            }
            st[ch].push(idx);
            answer.push_back(s[i]);
        }
        return answer;
    }
};
