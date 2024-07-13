#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

string postToPre(string s) {
    int n = s.size();
    stack<string>st;
    for(int i = 0;i < n;i++) {
        char ch = s[i];
        if(isOperand(ch))  { string check(1,ch); st.push(check); }
        else {
            string str1 = st.top(); st.pop();
            string str2 = st.top(); st.pop();

            string temp = string(1,ch) + str2 + str1;
            st.push(temp);
        }
    }
    string answer = st.top();
    return answer;
}

int main() {
    cout << postToPre("ABC/-AK/L-*") << endl;
}