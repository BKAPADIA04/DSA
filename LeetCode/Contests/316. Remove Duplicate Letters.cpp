class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string st;
        vector<int>lastOcc(26,-1);
        for(int i = 0;i < n;i++) {
            lastOcc[s[i] - 'a'] = i;
        }

        int usedMask = 0; // new way instead of visited

        for(int i = 0;i < n;i++) {
            char ch = s[i];
            int index = ch - 'a';

            // cout << i << endl;

            if(usedMask & (1 << index)) continue;

            while(st.size() > 0 && (ch < st.back()) && lastOcc[st.back() - 'a'] > i) {
                // cout << st.back() << endl;
                usedMask ^= 1 << (st.back() - 'a');
                st.pop_back();
            }

            st.push_back(ch);
            usedMask |= (1 << index);

            // cout << st << endl;
        }
        return st;
    }
};
