#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    if(s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
    stack<char>st;
    int n = s.size();
    for(int i = 0;i < n;i++) {
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
        else {
            if(!st.empty()) {
                char top = st.top();
                if(top == '(' && ch == ')') st.pop();
                else if(top == '{' && ch == '}') st.pop();
                else if(top == '[' && ch == ']') st.pop();
                else return false;
            }
            else return false;
        }
    }        
    if(st.empty()) return true;
    return false;
}

int main() {
    cout << isValid("({})") << endl;
}