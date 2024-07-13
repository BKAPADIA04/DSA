#include <bits/stdc++.h>
using namespace std;

int precedence(char ch) {
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return 0;
}


string infixToPostfix(string s) {
    string answer = "";
    stack<char>st;
    int n = s.size();

    for(int i = 0;i < n;i++) {
        char ch = s[i];
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) answer += ch;

        else if(ch == '(') st.push(ch);

        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') { answer += st.top(); st.pop(); }
            st.pop();
        }
        else {
            while(!st.empty() && ((precedence(ch) - precedence(st.top())) <= 0)) {
                answer += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }

    return answer;
}

int main() {
    cout << infixToPostfix("A*(B+C)/D") << endl;
    cout << infixToPostfix("a+b*(c^d-e)^(f+g*h)-i") << endl;
}