#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int n = s.size();
    stack<string>st;
    string ans = "";
    for(int i = 0;i < n; i++) {
        if(s[i] == ' ') {
            if(ans != "")
            {
                st.push(ans);
                ans = "";
            }
        }
        else {
            ans += s[i];
        }
    }

    if(ans != "") {
        st.push(ans);
    }

    ans = "";
    while(st.size()!=1)
    {
        ans+=st.top()+" ";
        st.pop();
    }
    ans+=st.top();
    return ans;
}


string reverseWords_(string s) {
    int n = s.size();
    string ans = "";
    string result = "";
    for(int i = 0;i < n; i++) {
        if(s[i] == ' ') {
            if(ans != "")
            {
                result = ans + " " + result;
                ans = "";
            }
        }
        else {
            ans += s[i];
        }
    }
    if(ans != "") result = ans + " " + result;
    return result.substr(0,result.size()-1);
}

int main() {
    string s="  hello world  ";
    cout << reverseWords(s) << endl;
    cout << reverseWords("the sky is blue") << endl;
    cout << reverseWords("a good   example") << endl;
    cout << reverseWords_(s) << endl;
    cout << reverseWords_("the sky is blue") << endl;
    cout << reverseWords_("a good   example") << endl;
}