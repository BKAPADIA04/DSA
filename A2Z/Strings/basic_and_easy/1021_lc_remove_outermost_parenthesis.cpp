#include <bits/stdc++.h>
using namespace std;


string removeOuterParentheses(string s) {
    int n = s.size();
    string ans = "";
    int i = 0; int sum = 1;
    for(int j = 1; j < n; j++) {
        if(s[j] == '(') sum += 1;
        else sum -= 1;

        if(sum == 0) {
            ans += s.substr(i+1,j-i-1);
            i = j + 1;
        }
    }
    return ans;
}

// Other Approach - Stack Approach
string removeOuterParentheses_(string s) {
    stack<char> stack;
    string ans="";
    for(int i=0;i<s.length();i++){
        if(stack.empty()) stack.push(s[i]);
        else{
            if(s[i]=='(') stack.push(s[i]);
            else stack.pop();
            if(!stack.empty()) ans+=s[i];
        }
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << removeOuterParentheses(str) << endl;
}