class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int>st;
        vector<int>pairs(n,-1);
        for(int i = 0;i < n;i++) {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')') {
                int j = st.top();
                st.pop();
                pairs[i] = j;
                pairs[j] = i;
            }
        }

        string answer = "";
        int direction = 1; int i = 0;
        while(i < n && i >= 0) {
            if(s[i] == '(' || s[i] == ')') {
                i = pairs[i];
                direction *= -1;
            }
            else {
                answer += s[i];
            }
            if(direction > 0) i++;
            if(direction < 0) i--;
        }
        return answer;
    }
};

/*
string reverseParentheses(string s) {
        int n = s.size();
        stack<char>st;
        for(int i = 0;i < n;i++) {
            if(s[i] != ')') {
                st.push(s[i]);
            }
            else {
                string temp = "";
                while(!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(int k = 0;k < temp.size();k++) {
                    st.push(temp[k]);
                }
            }
        }

        string answer = "";
        while(!st.empty()) {
            answer = st.top() + answer;
            st.pop();
        }
        return answer;
    }
    */
