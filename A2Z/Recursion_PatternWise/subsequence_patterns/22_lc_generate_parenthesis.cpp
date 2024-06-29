#include <bits/stdc++.h>
using namespace std;

void print(vector<string>temp) {
    for(string str:temp) cout << str << endl;
}

void generate(vector<string>&answer,string str,int i,int n,int open,int close) {
    if(i == (2*n)) {answer.push_back(str); return;}

    if(open < n) {
        generate(answer,str + "(",i+1,n,open+1,close);
    }

    if(close < open) {
        generate(answer,str + ")",i+1,n,open,close+1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string>ans;
    generate(ans,"",0,n,0,0);
    return ans;
}

int main() {
    vector<string>ans = generateParenthesis(3);
    for(string s:ans) { cout << s << endl;}
}