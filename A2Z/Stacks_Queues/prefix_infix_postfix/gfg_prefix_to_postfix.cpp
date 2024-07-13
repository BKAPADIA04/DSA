#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

string preToPost(string s) {
    int n = s.size();
    stack<string>st;
    reverse(s.begin(),s.end());
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
    reverse(answer.begin(),answer.end());
    return answer;
}

int main() {
    cout << preToPost("*-A/BC-/AKL") << endl;
}