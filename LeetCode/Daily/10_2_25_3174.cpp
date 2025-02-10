class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char>st;
        for(int i = 0;i < n;i++) {
            if(isalpha(s[i])) {
                st.push(s[i]);
            }
            else {
                if(!st.empty()) st.pop();
            }
        }
        string temp = "";
        while(!st.empty()) {
            temp = st.top() + temp;
            st.pop();
        }
        return temp;
    }
};
